/* -------------------------------------------------------------------------
//  File        :   interface_draw.h
//  Author      :   Sum
//  Datet       :   2014/6/11 11:38
//  Brief       :   
//
// -----------------------------------------------------------------------*/
#ifndef __INTERFACE_DRAW_H_
#define __INTERFACE_DRAW_H_

#include "define.h"
#include "html_object.h"
#include "css_object.h"

interface interface_draw
{
    virtual bool                init(tidHandle handle) = 0;
    virtual bool                uninit() = 0;
    virtual bool                drawLine(const tidPoint& posX, const tidPoint& posY, tidColor& color) = 0;
    virtual bool                drawRect(const tidRect& rect, tidColor& color) = 0;
    virtual bool                drawImg(tidImageObject* img, const tidPoint& pos) = 0;
    virtual bool                drawImg(tidImageObject* img, const tidRect& rect) = 0;
};

#endif // __INTERFACE_DRAW_H_