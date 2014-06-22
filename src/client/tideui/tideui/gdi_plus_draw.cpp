/* -------------------------------------------------------------------------
//  File        :   gdi_plus_draw.cpp
//  Author      :   Sum
//  Datet       :   2014/6/11 11:57
//  Brief       :   
//
// -----------------------------------------------------------------------*/
//
#include "stdafx.h"
#include "gdi_plus_draw.h"

gdi_plus_draw::gdi_plus_draw()
{
    m_handle = NULL;
}

gdi_plus_draw::~gdi_plus_draw()
{

}

bool gdi_plus_draw::init(tidHandle handle)
{
    m_handle = handle;
    Gdiplus::GdiplusStartupInput StartupInput;
    Gdiplus::GdiplusStartup(&m_gdiplusToken, &StartupInput, NULL);
    m_graphicsPtr = Gdiplus::Graphics::FromHDC(handle);
    return true;
}

bool gdi_plus_draw::uninit()
{
    if (m_graphicsPtr != nullptr)
    {
        delete m_graphicsPtr;
        m_graphicsPtr = nullptr;
    }
    Gdiplus::GdiplusShutdown(m_gdiplusToken);
    return true;
}

bool gdi_plus_draw::drawLine(const tidPoint& posX, const tidPoint& posY, tidColor& color)
{
    if (m_graphicsPtr == nullptr)
    {
        return false;
    }

    Gdiplus::Pen pen(color);
    Gdiplus::Status drawStatus = m_graphicsPtr->DrawLine(&pen,
        posX,
        posY);
    if (drawStatus != Gdiplus::Status::Ok)
    {
        return false;
    }
    return true;
}

bool gdi_plus_draw::drawRect(const tidRect& rect, tidColor& color)
{
    if (m_graphicsPtr == nullptr)
    {
        return false;
    }

    Gdiplus::Pen pen(color);
    Gdiplus::Status drawStatus = m_graphicsPtr->DrawRectangle(&pen,
        rect);
    if (drawStatus != Gdiplus::Status::Ok)
    {
        return false;
    }
    return true;
}

bool gdi_plus_draw::drawImg(tidImageObject* img, const tidPoint& pos)
{
    if (m_graphicsPtr == nullptr
        || img == nullptr)
    {
        return false;
    }

    Gdiplus::Status drawStatus = m_graphicsPtr->DrawImage((Gdiplus::Image*)img,
        pos);
    if (drawStatus != Gdiplus::Status::Ok)
    {
        return false;
    }
    return true;
}

bool gdi_plus_draw::drawImg(tidImageObject* img, const tidRect& rect)
{
    if (m_graphicsPtr == nullptr
        || img == nullptr)
    {
        return false;
    }

    Gdiplus::Status drawStatus = m_graphicsPtr->DrawImage((Gdiplus::Image*)img,
        rect);
    if (drawStatus != Gdiplus::Status::Ok)
    {
        return false;
    }
    return true;
}
