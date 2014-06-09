/* -------------------------------------------------------------------------
//  File        :   freedom_control_object_h5.h
//  Author      :   Sum
//  Datet       :   5015/5/15 1:08
//  Brief       :   
//
// -----------------------------------------------------------------------*/
#ifndef __FREEDOM_CONTROL_OBJECT_H5_H_
#define __FREEDOM_CONTROL_OBJECT_H5_H_

#include "freedom_control_object_base.h"

class freedom_control_object_h5 : public freedom_control_object_base
{
public:
    freedom_control_object_h5() {}
    virtual ~freedom_control_object_h5() {}

public:
    FREEDOM_INFO_BEGINE("h5", name)
        FREEDOM_DISPOSE_FUN(freedom_control_object_base::parseInfo)
        FREEDOM_GET_TEXT(text)
        FREEDOM_ARR_BEGINE()
            FREEDOM_ARR_STRING("align", align)
        FREEDOM_ARR_END()
    FREEDOM_INFO_END()

public:
    std::wstring            align;
};

#endif // __FREEDOM_CONTROL_OBJECT_H5_H_