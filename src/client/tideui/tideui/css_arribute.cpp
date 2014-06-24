/* -------------------------------------------------------------------------
//  File        :   css_arribute.cpp
//  Author      :   Sum
//  Datet       :   2014/6/22 12:47
//  Brief       :   
//
// -----------------------------------------------------------------------*/
//
#include "stdafx.h"
#include "css_arribute.h"
#include <assert.h>
#include "character_tool.h"
#include "define.h"

css_arribute::css_arribute()
{

}

css_arribute::~css_arribute()
{

}

bool css_arribute::set(const cssObjectArrtibute& arribute)
{
    return _setValue(arribute);
}

bool css_arribute::clear()
{
    return true;
}
