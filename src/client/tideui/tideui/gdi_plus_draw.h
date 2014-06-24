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
    virtual bool                init(tid::handle handle);
    virtual bool                uninit();
    virtual bool                drawLine(const tid::point& posX, const tid::point& posY, tid::color& color);
    virtual bool                drawRect(const tid::rect& rect, tid::color& color);
    virtual bool                drawImg(tid::imageObject* img, const tid::point& pos);
    virtual bool                drawImg(tid::imageObject* img, const tid::rect& rect);

private:
    tid::handle               m_handle;
    ULONG_PTR               m_gdiplusToken;
    Gdiplus::Graphics*      m_graphicsPtr;
};

#endif // __GDI_PLUS_DRAW_H_