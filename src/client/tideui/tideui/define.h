/* -------------------------------------------------------------------------
//  File        :   define.h
//  Author      :   Sum
//  Datet       :   2014/6/11 11:39
//  Brief       :   
//
// -----------------------------------------------------------------------*/
#ifndef __DEFINE_H_
#define __DEFINE_H_

#include <gdiplus.h>

namespace tid
{

typedef enum __emDrawType
{
    emDrawTypeGdiPlus               = 1,
    emDrawTypeDx                    = 2,
}emDrawType;

///> type
typedef Gdiplus::Color              color;
typedef HDC                         handle;
typedef Gdiplus::Rect               rect;
typedef Gdiplus::Point              point;
typedef Gdiplus::Image              imageObject;

typedef unsigned char               uint8;
typedef unsigned short              uint16;
typedef unsigned int                uint32;
typedef unsigned long long          uint64;
typedef char                        int8;
typedef short                       int16;
typedef int                         int32;
typedef long long                   int64;

}

#endif // __DEFINE_H_