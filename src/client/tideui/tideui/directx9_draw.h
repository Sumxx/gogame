/* -------------------------------------------------------------------------
//  File        :   directx9_draw.h
//  Author      :   Sum
//  Datet       :   2014/6/11 11:53
//  Brief       :   
//
// -----------------------------------------------------------------------*/
#ifndef __DIRECTX9_DRAW_H_
#define __DIRECTX9_DRAW_H_

#include "interface_draw.h"

class directx9_draw : public interface_draw
{
public:
    directx9_draw();
    virtual ~directx9_draw();

public:
    virtual bool                init(tidHandle handle);
    virtual bool                uninit();
    virtual bool                drawLine(const tidPoint& posX, const tidPoint& posY, tidColor& color);
    virtual bool                drawRect(const tidRect& rect, tidColor& color);
    virtual bool                drawImg(tidImageObject* img, const tidPoint& pos);
    virtual bool                drawImg(tidImageObject* img, const tidRect& rect);

private:
    tidHandle              m_handle;
};

#endif // __DIRECTX9_DRAW_H_