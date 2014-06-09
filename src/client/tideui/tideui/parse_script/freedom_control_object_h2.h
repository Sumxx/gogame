/* -------------------------------------------------------------------------
//  File        :   freedom_control_object_h2.h
//  Author      :   Sum
//  Datet       :   2014/5/13 1:08
//  Brief       :   
//
// -----------------------------------------------------------------------*/
#ifndef __FREEDOM_CONTROL_OBJECT_H2_H_
#define __FREEDOM_CONTROL_OBJECT_H2_H_

#include "freedom_control_object_base.h"

class freedom_control_object_h2 : public freedom_control_object_base
{
public:
    freedom_control_object_h2() {}
    virtual ~freedom_control_object_h2() {}

public:
    FREEDOM_INFO_BEGINE("h2", name)
        FREEDOM_DISPOSE_FUN(freedom_control_object_base::parseInfo)
        FREEDOM_GET_TEXT(text)
        FREEDOM_ARR_BEGINE()
            FREEDOM_ARR_STRING("align", align)
        FREEDOM_ARR_END()
    FREEDOM_INFO_END()

public:
    std::wstring            align;
};

#endif // __FREEDOM_CONTROL_OBJECT_H2_H_