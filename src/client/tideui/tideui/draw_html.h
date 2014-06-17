/* -------------------------------------------------------------------------
//  File        :   draw_html.h
//  Author      :   Sum
//  Datet       :   2014/6/17 16:30
//  Brief       :   
//
// -----------------------------------------------------------------------*/
#ifndef __DRAW_HTML_H_
#define __DRAW_HTML_H_

#include "gdi_plus_draw.h"
#include "directx9_draw.h"
#include "interface_draw.h"

class draw_html
{
public:
    draw_html();
    ~draw_html();

public:
    bool                init(drawHandle handle, emDrawType emType);
    bool                uninit();
    bool                draw(html_object* object);
    bool                update(html_object* object);
    bool                clear(html_object* object);

private:
    interface_draw*     _createDraw(emDrawType emType);

private:
    interface_draw*     m_drawPrt;
};

#endif // __DRAW_HTML_H_