/* -------------------------------------------------------------------------
//  File        :   freedom_control_object_title.h
//  Author      :   Sum
//  Datet       :   2014/5/12 2:51
//  Brief       :   
//
// -----------------------------------------------------------------------*/
#ifndef __FREEDOM_CONTROL_OBJECT_TITLE_H_
#define __FREEDOM_CONTROL_OBJECT_TITLE_H_

#include "freedom_control_object_base.h"

class freedom_control_object_title : public freedom_control_object_base
{
public:
    freedom_control_object_title() {}
    virtual ~freedom_control_object_title() {}

public:
    FREEDOM_INFO_BEGINE("title", name)
        FREEDOM_DISPOSE_FUN(freedom_control_object_base::parseInfo)
        FREEDOM_GET_TEXT(text)
    FREEDOM_INFO_END()
};

#endif // __FREEDOM_CONTROL_OBJECT_TITLE_H_