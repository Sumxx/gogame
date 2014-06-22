/* -------------------------------------------------------------------------
//  File        :   css_object.h
//  Author      :   Sum
//  Datet       :   2014/6/9 16:11
//  Brief       :   
//
// -----------------------------------------------------------------------*/
#ifndef __CSS_OBJECT_H_
#define __CSS_OBJECT_H_

#include "css_name.h"
#include <map>
#include <vector>
#include "css_arribute.h"

typedef std::vector<css_name>                            cssNameGroup;

struct css_objcet
{
    cssNameGroup            cssGroup;
    css_arribute            cssArribute;
};

#endif // __CSS_OBJECT_H_