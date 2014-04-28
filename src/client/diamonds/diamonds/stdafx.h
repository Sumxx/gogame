// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//
#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

#include "irrlicht/irrlicht.h"

#ifdef _IRR_WINDOWS_
#ifdef _DEBUG
#pragma comment(lib,"irrlicht_d.lib")
#else
#pragma comment(lib,"irrlicht.lib")
#endif // _DEBUG
#endif

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;