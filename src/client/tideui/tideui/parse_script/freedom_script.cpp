/* -------------------------------------------------------------------------
//  File        :   freedom_script.cpp
//  Author      :   Sum
//  Datet       :   2014/5/12 1:03
//  Brief       :   
//
// -----------------------------------------------------------------------*/
//
#include "stdafx.h"
#include "freedom_script.h"
#include <atlbase.h>
#include "freedom_control_object_title.h"
#include "freedom_control_object_script.h"
#include "freedom_control_object_style.h"
#include "freedom_control_object_h1.h"
#include "freedom_control_object_h2.h"
#include "freedom_control_object_h3.h"
#include "freedom_control_object_h4.h"
#include "freedom_control_object_h5.h"
#include "freedom_control_object_h6.h"

#define FREEDOM_PRODUCTION_OBJECT(nameStr, comparisonValue, type) \
    if (comparisonValue == nameStr) \
    { \
        return new type; \
    }

freedom_script::freedom_script()
{

}

freedom_script::~freedom_script()
{

}

bool freedom_script::parseScriptFile(const std::wstring& filePath)
{
    if (filePath.empty())
    {
        return false;
    }

    TiXmlDocument doc;
    if (!doc.LoadFile(CW2A(filePath.c_str(), CP_UTF8).m_psz))
    {
        return false;
    }

    return _parse(doc);
}

bool freedom_script::parseBuffer(void* bufferPtr, int bufferLen)
{
//     if (bufferPtr == NULL)
//     {
//         return false;
//     }
// 
//     TiXmlDocument doc;
//     if (!doc.Parse(filePath.c_str()))
//     {
//         return false;
//     }
// 
//     return _parse(doc);
    return true;
}

int freedom_script::getControlNum()
{
    return m_controlPoolHead.size();
}

freedom_control_object_base* freedom_script::getBeineObject()
{
    return nullptr;
}

freedom_control_object_base* freedom_script::getNextObject()
{
    return nullptr;
}

freedom_control_object_base* freedom_script::getEndObject()
{
    return nullptr;
}

bool freedom_script::_parse(TiXmlDocument& doc)
{
    TiXmlElement* rootElement = doc.RootElement();
    if (!rootElement)
    {
        return false;
    }

    std::string rootName = rootElement->ValueStr();
    if (rootName.empty()
        || rootName != "html")
    {
        return false;
    }

    _parseHead(rootElement);
    _parseBody(rootElement);
    return true;
}

bool freedom_script::_parseHead(TiXmlElement* rootElement)
{
    assert(rootElement != nullptr);
    for (TiXmlElement* node = rootElement->FirstChildElement();
        node != nullptr;
        node = node->NextSiblingElement())
    {
        if (node->ValueStr() == "head")
        {
            _parseBaseElement(node);
        }
    }
    return true;
}

bool freedom_script::_parseBody(TiXmlElement* rootElement)
{
    assert(rootElement != nullptr);
    for (TiXmlElement* node = rootElement->FirstChildElement();
        node != nullptr;
        node = node->NextSiblingElement())
    {
        if (node->ValueStr() == "body")
        {
            _parseBaseElement(node);
        }
    }
    return true;
}

bool freedom_script::_parseBaseElement(TiXmlElement* prentsElement)
{
    assert(prentsElement != nullptr);
    for (TiXmlElement* node = prentsElement->FirstChildElement();
        node != nullptr;
        node = node->NextSiblingElement())
    {
        //freedom_control_object_base* object = _productionObject(node);
        freedom_control_object_base* object = new freedom_control_object_base;
        if (!object)
        {
            continue;
        }

        if (object->parseInfo(node))
        {
            m_controlPoolHead.push_back(object);
        }
        else
        {
            delete object;
            object = nullptr;
        }
    }
    return true;
}

freedom_control_object_base* freedom_script::_productionObject(TiXmlElement* prentsElement)
{
    assert(prentsElement != nullptr);
    const char* prentsElementNameChar = prentsElement->Value();
    if (prentsElementNameChar == nullptr)
    {
        return nullptr;
    }

    std::string prentsElementName = prentsElementNameChar;
    FREEDOM_PRODUCTION_OBJECT("title",
        prentsElementName,
        freedom_control_object_title);

    FREEDOM_PRODUCTION_OBJECT("script",
        prentsElementName,
        freedom_control_object_script);

    FREEDOM_PRODUCTION_OBJECT("style",
        prentsElementName,
        freedom_control_object_style);

    FREEDOM_PRODUCTION_OBJECT("h1",
        prentsElementName,
        freedom_control_object_h1);

    FREEDOM_PRODUCTION_OBJECT("h2",
        prentsElementName,
        freedom_control_object_h2);

    FREEDOM_PRODUCTION_OBJECT("h3",
        prentsElementName,
        freedom_control_object_h3);

    FREEDOM_PRODUCTION_OBJECT("h4",
        prentsElementName,
        freedom_control_object_h4);

    FREEDOM_PRODUCTION_OBJECT("h5",
        prentsElementName,
        freedom_control_object_h5);

    FREEDOM_PRODUCTION_OBJECT("h6",
        prentsElementName,
        freedom_control_object_h6);

    return nullptr;
}
