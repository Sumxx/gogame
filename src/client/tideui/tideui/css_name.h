/* -------------------------------------------------------------------------
//  File        :   css_name.h
//  Author      :   Sum
//  Datet       :   2014/6/10 10:27
//  Brief       :   
//
// -----------------------------------------------------------------------*/
#ifndef __CSS_NAME_H_
#define __CSS_NAME_H_

#include <string>
#include <list>

typedef std::list<std::string>             cssObjectRelation;
typedef std::list<std::string>             cssObjectName;

struct css_name
{
    cssObjectRelation       relationList;
    cssObjectName           nameList;
};

#endif // __CSS_NAME_H_