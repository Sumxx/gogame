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
    virtual bool                init(drawHandle handle) = 0;
    virtual bool                uninit() = 0;
    virtual bool                drawLine() = 0;
    virtual bool                drawRect() = 0;
    virtual bool                drawImg() = 0;
};

#endif // __INTERFACE_DRAW_H_