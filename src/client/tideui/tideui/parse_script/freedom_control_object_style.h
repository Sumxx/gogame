/* -------------------------------------------------------------------------
//  File        :   freedom_control_object_style.h
//  Author      :   Sum
//  Datet       :   2014/5/13 0:31
//  Brief       :   
//
// -----------------------------------------------------------------------*/
#ifndef __FREEDOM_CONTROL_OBJECT_STYLE_H_
#define __FREEDOM_CONTROL_OBJECT_STYLE_H_

#include "freedom_control_object_base.h"

class freedom_control_object_style : public freedom_control_object_base
{
public:
    freedom_control_object_style() {}
    virtual ~freedom_control_object_style() {}

public:
    FREEDOM_INFO_BEGINE("style", name)
        FREEDOM_DISPOSE_FUN(freedom_control_object_base::parseInfo)
        FREEDOM_GET_TEXT(text)
        FREEDOM_ARR_BEGINE()
            FREEDOM_ARR_STRING("type", type)
        FREEDOM_ARR_END()
    FREEDOM_INFO_END()

public:
    std::wstring            type;
};


#endif // __FREEDOM_CONTROL_OBJECT_STYLE_H_