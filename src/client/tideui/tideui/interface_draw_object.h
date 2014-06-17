/* -------------------------------------------------------------------------
//  File        :   interface_draw_object.h
//  Author      :   Sum
//  Datet       :   2014/6/16 23:44
//  Brief       :   
//
// -----------------------------------------------------------------------*/
#ifndef __INTERFACE_DRAW_OBJECT_H_
#define __INTERFACE_DRAW_OBJECT_H_

#include "define.h"

interface interface_draw_object
{
    virtual bool                draw(interface_draw* draw) = 0;
    virtual bool                update() = 0;
    virtual void                pos(int x, int y) = 0;
    virtual void                size(int width, int height) = 0;
};

#endif // __INTERFACE_DRAW_OBJECT_H_