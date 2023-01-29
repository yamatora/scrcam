---
title: scrcam
abstract:
    Screen to Virtual Camera with Direct Show 
---

```
salt
{
    {T
        + [scrcam]
        ++ doc
        +++ scrcam.md   | This document

        ++ src      | ソース
        ++ doc      | ドキュメント
        ++ data     | データ
    }
}
```

### Predefined Clipboard Formats

```cpp title="WinUser.h"
/*
 * Predefined Clipboard Formats
 */
#define CF_TEXT             1
#define CF_BITMAP           2
#define CF_METAFILEPICT     3
#define CF_SYLK             4
#define CF_DIF              5
#define CF_TIFF             6
#define CF_OEMTEXT          7
#define CF_DIB              8
#define CF_PALETTE          9
#define CF_PENDATA          10
#define CF_RIFF             11
#define CF_WAVE             12
#define CF_UNICODETEXT      13
#define CF_ENHMETAFILE      14
#if(WINVER >= 0x0400)
#define CF_HDROP            15
#define CF_LOCALE           16
#endif /* WINVER >= 0x0400 */
#if(WINVER >= 0x0500)
#define CF_DIBV5            17
#endif /* WINVER >= 0x0500 */

#if(WINVER >= 0x0500)
#define CF_MAX              18
#elif(WINVER >= 0x0400)
#define CF_MAX              17
#else
#define CF_MAX              15
#endif
```