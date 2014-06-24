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
    m_drawPtr = nullptr;
}

draw_html::~draw_html()
{

}

bool draw_html::init(tid::handle handle, tid::emDrawType emType)
{
    if (handle == NULL)
    {
        return false;
    }

    m_drawPtr = _createDraw(emType);
    if (m_drawPtr == nullptr)
    {
        return false;
    }
    return m_drawPtr->init(handle);
}

bool draw_html::uninit()
{
    if (m_drawPtr)
    {
        delete m_drawPtr;
        m_drawPtr = nullptr;
    }
    return true;
}

bool draw_html::draw(html_object* object, css_objcet* cssObject)
{
    if (m_drawPtr == nullptr
        || object == nullptr)
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

        if (drawobject->draw(m_drawPtr, cssObject))
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

interface_draw* draw_html::_createDraw(tid::emDrawType emType)
{
    switch (emType)
    {
    case tid::emDrawTypeGdiPlus:
        {
            return new gdi_plus_draw;
        }
    case tid::emDrawTypeDx:
        {
            return new directx9_draw;
        }
    }
    return nullptr;
}
