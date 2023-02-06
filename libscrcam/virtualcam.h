#pragma once

#include "pch.h"

#define WIN32_LEAN_AND_MEAN

#pragma comment(lib, "kernel32")
#pragma comment(lib, "user32")
#pragma comment(lib, "gdi32")
#pragma comment(lib, "advapi32")
#pragma comment(lib, "winmm")
#pragma comment(lib, "ole32")
#pragma comment(lib, "oleaut32")

#pragma comment(lib, "strmbase.lib")

#define TEMPLATE_NAME	(L"scrcam")
#define FILTER_NAME		(TEMPLATE_NAME)
#define WIN_WIDTH 1280
#define WIN_HEIGHT 720
#define PIXEL_BIT 24

#include <Windows.h>
#include <direct.h>
#include <source.h>

class CSimpleVirtualCamFilterStream;

class CSimpleVirtualCamFilter : public CSource {
public:
	static DLL_API int CreateInstance(int lpunk, HRESULT* phr);
	STDMETHODIMP QueryInterface(REFIID riid, void** ppv);

//private:
};