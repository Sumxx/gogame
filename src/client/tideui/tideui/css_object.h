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

typedef std::map<std::string, std::vector<std::string> > cssObjectArrtibute;
typedef std::vector<css_name>                            cssNameGroup;

struct css_objcet
{
public:
    cssNameGroup            cssGroup;
    cssObjectArrtibute      cssArrMap;
};

#endif // __CSS_OBJECT_H_