// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
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