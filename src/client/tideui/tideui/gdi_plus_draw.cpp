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

bool gdi_plus_draw::init(drawHandle handle)
{
    m_handle = handle;
    return true;
}

bool gdi_plus_draw::uninit()
{
    return true;
}

bool gdi_plus_draw::drawLine()
{
    return true;
}

bool gdi_plus_draw::drawRect()
{
    return true;
}

bool gdi_plus_draw::drawImg()
{
    return true;
}
