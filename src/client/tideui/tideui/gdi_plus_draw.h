/* -------------------------------------------------------------------------
//  File        :   gdi_plus_draw.h
//  Author      :   Sum
//  Datet       :   2014/6/11 11:54
//  Brief       :   
//
// -----------------------------------------------------------------------*/
#ifndef __GDI_PLUS_DRAW_H_
#define __GDI_PLUS_DRAW_H_

#include <GdiPlus.h>
#include "interface_draw.h"

#pragma comment(lib,"GdiPlus.lib")

class gdi_plus_draw : public interface_draw
{
public:
    gdi_plus_draw();
    virtual ~gdi_plus_draw();

public:
    virtual bool                init(tidHandle handle);
    virtual bool                uninit();
    virtual bool                drawLine(const tidPoint& posX, const tidPoint& posY, tidColor& color);
    virtual bool                drawRect(const tidRect& rect, tidColor& color);
    virtual bool                drawImg(tidImageObject* img, const tidPoint& pos);
    virtual bool                drawImg(tidImageObject* img, const tidRect& rect);

private:
    tidHandle               m_handle;
    ULONG_PTR               m_gdiplusToken;
    Gdiplus::Graphics*      m_graphicsPtr;
};

#endif // __GDI_PLUS_DRAW_H_