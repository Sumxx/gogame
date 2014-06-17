/* -------------------------------------------------------------------------
//  File        :   gdi_plus_draw.h
//  Author      :   Sum
//  Datet       :   2014/6/11 11:54
//  Brief       :   
//
// -----------------------------------------------------------------------*/
#ifndef __GDI_PLUS_DRAW_H_
#define __GDI_PLUS_DRAW_H_

#include "interface_draw.h"

class gdi_plus_draw : public interface_draw
{
public:
    gdi_plus_draw();
    virtual ~gdi_plus_draw();

public:
    virtual bool                init(drawHandle handle);
    virtual bool                uninit();
    virtual bool                drawLine();
    virtual bool                drawRect();
    virtual bool                drawImg();

private:
    drawHandle              m_handle;
};

#endif // __GDI_PLUS_DRAW_H_