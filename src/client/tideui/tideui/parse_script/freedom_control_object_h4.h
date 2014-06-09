/* -------------------------------------------------------------------------
//  File        :   freedom_control_object_h4.h
//  Author      :   Sum
//  Datet       :   4014/5/14 1:08
//  Brief       :   
//
// -----------------------------------------------------------------------*/
#ifndef __FREEDOM_CONTROL_OBJECT_H4_H_
#define __FREEDOM_CONTROL_OBJECT_H4_H_

#include "freedom_control_object_base.h"

class freedom_control_object_h4 : public freedom_control_object_base
{
public:
    freedom_control_object_h4() {}
    virtual ~freedom_control_object_h4() {}

public:
    FREEDOM_INFO_BEGINE("h4", name)
        FREEDOM_DISPOSE_FUN(freedom_control_object_base::parseInfo)
        FREEDOM_GET_TEXT(text)
        FREEDOM_ARR_BEGINE()
            FREEDOM_ARR_STRING("align", align)
        FREEDOM_ARR_END()
    FREEDOM_INFO_END()

public:
    std::wstring            align;
};

#endif // __FREEDOM_CONTROL_OBJECT_H4_H_