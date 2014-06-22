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

typedef enum __emDrawType
{
    emDrawTypeGdiPlus               = 1,
    emDrawTypeDx                    = 2,
}emDrawType;

///> type
typedef Gdiplus::Color              tidColor;
typedef HDC                         tidHandle;
typedef Gdiplus::Rect               tidRect;
typedef Gdiplus::Point              tidPoint;
typedef Gdiplus::Image              tidImageObject;

#endif // __DEFINE_H_