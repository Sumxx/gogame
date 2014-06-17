/* -------------------------------------------------------------------------
//  File        :   define.h
//  Author      :   Sum
//  Datet       :   2014/6/11 11:39
//  Brief       :   
//
// -----------------------------------------------------------------------*/
#ifndef __DEFINE_H_
#define __DEFINE_H_

typedef enum __emDrawType
{
    emDrawTypeGdiPlus               = 1,
    emDrawTypeDx                    = 2,
}emDrawType;

typedef HDC    drawHandle;
typedef RECT   drawRect;

///> type
typedef unsigned int tidcolor;

#endif // __DEFINE_H_