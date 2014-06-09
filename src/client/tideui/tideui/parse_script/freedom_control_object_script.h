/* -------------------------------------------------------------------------
//  File        :   freedom_control_object_script.h
//  Author      :   Sum
//  Datet       :   2014/5/12 16:22
//  Brief       :   
//
// -----------------------------------------------------------------------*/
#ifndef __FREEDOM_CONTROL_OBJECT_SCRIPT_H_
#define __FREEDOM_CONTROL_OBJECT_SCRIPT_H_

#include "freedom_control_object_base.h"

class freedom_control_object_script : public freedom_control_object_base
{
public:
    freedom_control_object_script() {}
    virtual ~freedom_control_object_script() {}

public:
    FREEDOM_INFO_BEGINE("script", name)
        FREEDOM_DISPOSE_FUN(freedom_control_object_base::parseInfo)
        FREEDOM_GET_TEXT(text)
        FREEDOM_ARR_BEGINE()
            FREEDOM_ARR_STRING("type", scriptType)
            FREEDOM_ARR_STRING("src", srcPath)
        FREEDOM_ARR_END()
    FREEDOM_INFO_END()

public:
    std::wstring            scriptType;
    std::wstring            srcPath;
};

#endif // __FREEDOM_CONTROL_OBJECT_SCRIPT_H_