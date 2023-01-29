#include "pch.h"
#include <Windows.h>

///	Macro
//#define GET_CBD_HANDLE(format) GlobalLock(GetClipboardData(format))	//	Get locked clipboard data handle pointer

/// <summary>
/// Whether image data in clipboard
/// </summary>
/// <returns></returns>
DLL_API bool hasClipboardImage() {
	if (OpenClipboard(NULL)) {
		return IsClipboardFormatAvailable(CF_DIB);
	}
	return false;
}

/// <summary>
/// Get image info
/// </summary>
/// <param name="width">Image width</param>
/// <param name="height">Image height</param>
/// <param name="bitsPerPixel">Image data size per pixel</param>
/// <returns></returns>
DLL_API bool getClipboardImageSize(int* width, int* height, int* bitsPerPixel) {
	bool result = false;
	if (OpenClipboard(NULL) && IsClipboardFormatAvailable(CF_DIB)) {
		BITMAPINFO* pData = (BITMAPINFO*)LocalLock(GetClipboardData(CF_DIB));
		if (pData != nullptr) {
			*width = pData->bmiHeader.biWidth;
			*height = pData->bmiHeader.biHeight;
			*bitsPerPixel = pData->bmiHeader.biBitCount;
			LocalUnlock(pData);
			result = true;
		}
	}
	CloseClipboard();
	return result;
}

/// <summary>
/// Get image data.
/// Only support 24bit(JPEG) or 32bit(PNG-32) image.
/// </summary>
/// <param name="buffer"></param>
/// <returns>Destination buffer</returns>
DLL_API bool getClipboardImage(unsigned char* buffer) {
	bool result = false;
	if (OpenClipboard(NULL) && IsClipboardFormatAvailable(CF_DIB)) {
		BITMAPINFO* pData = (BITMAPINFO*)LocalLock(GetClipboardData(CF_DIB));
		if (pData != nullptr) {
			int width, height, bitsPerPixel;
			getClipboardImageSize(&width, &height, &(bitsPerPixel));

			if (bitsPerPixel == 24 || bitsPerPixel == 32) {
				unsigned char* pImgData = (unsigned char*)pData + pData->bmiHeader.biSize;
				int bytesPerPixel = bitsPerPixel / 8;
				if (pData->bmiHeader.biCompression == BI_BITFIELDS) {
					pImgData += 4 * 3;
				}
				int bytesPerLine = width * bytesPerPixel;
				if (bytesPerLine % 4 != 0) {
					bytesPerLine += 4 - (bytesPerLine % 4);
				}

				unsigned char* dst = buffer;
				unsigned char* src = pImgData;
				for (int h = 0; h < height; h++) {
					memcpy(
						dst + width * h * bytesPerPixel,
						src + h * bytesPerLine,
						width * bytesPerPixel
					);
				}
				result = true;
			}
			LocalUnlock(pData);
		}
	}
	CloseClipboard();
	return result;
}