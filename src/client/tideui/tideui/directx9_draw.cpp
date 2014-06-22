/* -------------------------------------------------------------------------
//  File        :   directx9_draw.cpp
//  Author      :   Sum
//  Datet       :   2014/6/17 17:17
//  Brief       :   
//
// -----------------------------------------------------------------------*/
//
#include "stdafx.h"
#include "directx9_draw.h"

directx9_draw::directx9_draw()
{

}

directx9_draw::~directx9_draw()
{

}

bool directx9_draw::init(tidHandle handle)
{
    return true;
}

bool directx9_draw::uninit()
{
    return true;
}

bool directx9_draw::drawLine(const tidPoint& posX, const tidPoint& posY, tidColor& color)
{
    return true;
}

bool directx9_draw::drawRect(const tidRect& rect, tidColor& color)
{
    return true;
}

bool directx9_draw::drawImg(tidImageObject* img, const tidRect& rect)
{
    return true;
}

bool directx9_draw::drawImg(tidImageObject* img, const tidPoint& pos)
{
    return true;
}
