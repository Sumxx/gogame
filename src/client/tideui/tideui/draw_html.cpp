/* -------------------------------------------------------------------------
//  File        :   draw_html.cpp
//  Author      :   Sum
//  Datet       :   2014/6/17 16:36
//  Brief       :   
//
// -----------------------------------------------------------------------*/
//
#include "stdafx.h"
#include "draw_html.h"
#include "interface_draw_object.h"
#include "draw_object_factory.h"

draw_html::draw_html()
{
    m_drawPrt = nullptr;
}

draw_html::~draw_html()
{

}

bool draw_html::init(drawHandle handle, emDrawType emType)
{
    if (handle == NULL)
    {
        return false;
    }

    m_drawPrt = _createDraw(emType);
    if (m_drawPrt == nullptr)
    {
        return false;
    }
    return m_drawPrt->init(handle);
}

bool draw_html::uninit()
{
    if (m_drawPrt)
    {
        delete m_drawPrt;
        m_drawPrt = nullptr;
    }
    return true;
}

bool draw_html::draw(html_object* object)
{
    if (m_drawPrt == nullptr)
    {
        return false;
    }

    interface_draw_object* drawobject = nullptr;
    bool returnValue = false;
    do 
    {
        drawobject = draw_object_factory::createObject(object);
        if (drawobject == nullptr)
        {
            break;
        }

        if (drawobject->draw(m_drawPrt))
        {
            break;
        }

        returnValue = true;
    } while (false);

    draw_object_factory::deleteObject(drawobject);
    return returnValue;
}

bool draw_html::update(html_object* object)
{
    return true;
}

bool draw_html::clear(html_object* object)
{
    return true;
}

interface_draw* draw_html::_createDraw(emDrawType emType)
{
    switch (emType)
    {
    case emDrawTypeGdiPlus:
        {
            return new gdi_plus_draw;
        }
    case emDrawTypeDx:
        {
            return new directx9_draw;
        }
    }
    return nullptr;
}
