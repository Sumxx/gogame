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

class draw_head : public interface_draw_object
{
public:
    draw_head()
    {

    }
    virtual ~draw_head()
    {

    }

    virtual bool                draw(interface_draw* draw)
    {
        if (draw == nullptr)
        {
            return false;
        }
        draw->drawRect();
        return true;
    }

    virtual bool                update()
    {
        return true;
    }

    virtual void                pos(int x, int y)
    {
        m_rect.left = x;
        m_rect.top = y;
    }

    virtual void                size(int width, int height)
    {
        m_rect.right = m_rect.left + width;
        m_rect.bottom = m_rect.top + height;
    }

private:
    drawRect                m_rect;
};

#endif // __DRAW_HEAD_H_