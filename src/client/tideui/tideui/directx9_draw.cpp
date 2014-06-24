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

bool directx9_draw::init(tid::handle handle)
{
    return true;
}

bool directx9_draw::uninit()
{
    return true;
}

bool directx9_draw::drawLine(const tid::point& posX, const tid::point& posY, tid::color& color)
{
    return true;
}

bool directx9_draw::drawRect(const tid::rect& rect, tid::color& color)
{
    return true;
}

bool directx9_draw::drawImg(tid::imageObject* img, const tid::rect& rect)
{
    return true;
}

bool directx9_draw::drawImg(tid::imageObject* img, const tid::point& pos)
{
    return true;
}
