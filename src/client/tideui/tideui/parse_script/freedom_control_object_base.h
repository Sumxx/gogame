/* -------------------------------------------------------------------------
//  File        :   freedom_control_object_base.h
//  Author      :   Sum
//  Datet       :   2014/5/12 15:04
//  Brief       :   
//
// -----------------------------------------------------------------------*/
#ifndef __FREEDOM_CONTROL_OBJECT_BASE_H_
#define __FREEDOM_CONTROL_OBJECT_BASE_H_

#include "freedom_control_object.h"

class freedom_control_object_base : public freedom_control_object
{
public:
    freedom_control_object_base() {}
    virtual ~freedom_control_object_base() {}

public:
    FREEDOM_INFO_BEGINE_ANY(name)
        FREEDOM_DISPOSE_FUN(freedom_control_object::parseInfo)
        FREEDOM_ARR_BEGINE()
            FREEDOM_ARR_STRING("class", className)
            FREEDOM_ARR_STRING("style", styleName)
            FREEDOM_ARR_STRING("id", id)
            FREEDOM_ARR_STRING("title", titleInfo)
        FREEDOM_ARR_END()
    FREEDOM_INFO_END()

private:
    typedef std::vector<freedom_control_object_base*> _controlPoolType;
    typedef std::map<std::string, std::string>        _controlArrPoolType;

public:
    std::wstring            className;
    std::wstring            styleName;
    std::wstring            titleInfo;
    std::wstring            id;
    _controlPoolType        objectVec;
    _controlArrPoolType     objectArrMap;
};

#endif // __FREEDOM_CONTROL_OBJECT_BASE_H_