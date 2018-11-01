#pragma once
#include <Windows.h>
#include "gdiplus.h"
#include <string>

#pragma comment(lib, "Gdiplus.lib")

int GetEncoderClsid(const WCHAR* format, CLSID* pClsid);
void screenshot(POINT a, POINT b);
int scr();