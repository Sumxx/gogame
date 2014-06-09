/* -------------------------------------------------------------------------
//  File        :   freedom_control_object.h
//  Author      :   Sum
//  Datet       :   2014/5/12 0:35
//  Brief       :   
//
// -----------------------------------------------------------------------*/
#ifndef __FREEDOM_CONTROL_OBJECT_H_
#define __FREEDOM_CONTROL_OBJECT_H_

#include <string>
#include <vector>
#include <map>
#include <atlbase.h>
#include "tinyxml\tinyxml.h"

#define FREEDOM_INFO_BEGINE(name, value) \
bool parseInfo(TiXmlElement* node) \
{ \
    assert(node != nullptr); \
    const char* objectNameChar = node->Value(); \
    const char* objectTextChar = node->GetText(); \
    if (!objectNameChar) \
    { \
        return false; \
    } \
    \
    std::string objectName = objectNameChar; \
    if (objectName != name) \
    { \
        return false; \
    } \
    value = objectName;

#define FREEDOM_INFO_BEGINE_ANY(value) \
    bool parseInfo(TiXmlElement* node) \
    { \
    assert(node != nullptr); \
    const char* objectNameChar = node->Value(); \
    if (!objectNameChar) \
    { \
        return false; \
    } \
    \
    std::string objectName = objectNameChar; \
    value = objectName;

#define FREEDOM_DISPOSE_FUN(value) \
    value(node);

#define FREEDOM_GET_TEXT(valueW) \
    if(objectTextChar != nullptr) \
    { \
        valueW = CA2W(objectTextChar, CP_UTF8).m_psz; \
    }

#define FREEDOM_ARR_BEGINE() \
    const char* objectArrNameChar = nullptr; \
    const char* objectArrValueChar = nullptr; \
    std::string objectArrName; \
    std::string objectArrValue; \
    for (TiXmlAttribute* nodeArr = node->FirstAttribute(); \
        nodeArr != nullptr; \
        nodeArr = nodeArr->Next()) \
    { \
        objectArrNameChar = nodeArr->Name(); \
        if (!objectArrNameChar) \
        { \
            continue; \
        } \
        objectArrValueChar = nodeArr->Value(); \
        if (!objectArrNameChar) \
        { \
            continue; \
        } \
        objectArrName = objectArrNameChar; \
        objectArrValue = objectArrValueChar;

#define FREEDOM_ARR_STRING(name, valueW) \
    if (name == objectArrName) \
    { \
        valueW = CA2W(objectArrValue.c_str()).m_psz; \
    }

#define FREEDOM_ARR_INT(name, value) \
    if (name == objectArrName) \
    { \
        value = atoi(objectArrValue.c_str()); \
    }

#define FREEDOM_ARR_ALL_MAP(value) \
        value[objectArrName] = objectArrValue;

#define FREEDOM_ARR_END() \
    }

#define FREEDOM_INFO_END() \
    return true; \
}

class freedom_control_object
{
public:
    freedom_control_object() {}
    virtual ~freedom_control_object() {}

public:
    virtual bool parseInfo(TiXmlElement* node) { return true; }

public:
    std::string         name;
    std::wstring        text;
};

#endif // __FREEDOM_CONTROL_OBJECT_H_