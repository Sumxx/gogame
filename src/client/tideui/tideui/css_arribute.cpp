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

unsigned long css_arribute::_convertColor2Int(const std::string& colorValue)
{
    if (colorValue.empty())
    {
        return false;
    }
    bool isHexValue = false;
    bool isRGBValue = false;
    unsigned long longValue = 0;
    std::string hexStringValue = "0x";
    for (char c : colorValue)
    {
        if (!isHexValue
            && !isRGBValue)
        {
            if (c == '#')
            {
                isHexValue = true;
                continue;
            }
            if (c == 'R')
            {
                isRGBValue = true;
                continue;
            }
        }
        if (isHexValue)
        {
            hexStringValue += c;
        }
    }

    if (isHexValue)
    {
        char* strtolErr = nullptr;
        longValue = strtol(hexStringValue.c_str(), &strtolErr, 16);
        if (strcmp(strtolErr, "\0") != 0)
        {
            return 0;
        }
        longValue += 4278190080;
    }
    return longValue;
}
