/* -------------------------------------------------------------------------
//  File        :   draw_head.h
//  Author      :   Sum
//  Datet       :   2014/6/17 2:02
//  Brief       :   
//
// -----------------------------------------------------------------------*/
#ifndef __DRAW_HEAD_H_
#define __DRAW_HEAD_H_

#include "interface_draw_object.h"
#include "interface_draw.h"
#include "css_arribute.h"

class draw_head : public interface_draw_object
{
public:
    draw_head()
    {

    }
    virtual ~draw_head()
    {

    }

    virtual bool                draw(interface_draw* draw, css_objcet* cssObject)
    {
        if (draw == nullptr)
        {
            return false;
        }

        int width = 0;
        int height = 0;
        draw->drawRect(tid::rect(0, 0, cssObject->cssArribute.width, cssObject->cssArribute.height),
            tid::color(cssObject->cssArribute.background_color));
//         draw->drawImg(tidImageObject::FromFile(L"D:\\Desktop\\1.jpg"),
//             tidPoint(0,0));
        return true;
    }

    virtual bool                update()
    {
        return true;
    }

    virtual void                pos(int x, int y)
    {
        m_rect.X = x;
        m_rect.Y = y;
    }

    virtual void                size(int width, int height)
    {
        m_rect.Width = width;
        m_rect.Height = height;
    }

private:
    tid::rect                m_rect;
};

#endif // __DRAW_HEAD_H_