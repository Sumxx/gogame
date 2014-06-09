/* -------------------------------------------------------------------------
//  File        :   html_object.cpp
//  Author      :   Sum
//  Datet       :   2014/6/2 3:11
//  Brief       :   
//
// -----------------------------------------------------------------------*/
//
#include "stdafx.h"
#include "html_object.h"

html_object::html_object()
{

}

html_object::~html_object()
{

}

bool html_object::parse(TiXmlNode* node)
{
    if (node == nullptr)
    {
        return false;
    }

    _parseName(node);
    _parseText(node->ToElement());
    parseArrtibute(node->ToElement());

    for (TiXmlNode* chiledNode = node->FirstChildElement();
        chiledNode != nullptr;
        chiledNode = chiledNode->NextSiblingElement())
    {
        html_object* chiledObject = new html_object;
        if (!chiledObject)
        {
            continue;
        }
        if (chiledObject->parse(chiledNode))
        {
            m_chiledNodeVec.push_back(chiledObject);
        }
    }
    return true;
}

bool html_object::parseArrtibute(TiXmlElement* node)
{
    if (node == nullptr)
    {
        return false;
    }
    for (TiXmlAttribute* nodeArr = node->FirstAttribute();
        nodeArr != nullptr;
        nodeArr = nodeArr->Next())
    {
        if (node == nullptr)
        {
            continue;
        }

        const char* nodeArrName = nodeArr->Name();
        const char* nodeArrValue = nodeArr->Value();
        if (nodeArrName && nodeArrValue)
        {
            m_arributeMap[nodeArrName] = nodeArrValue;
        }
    }
    return true;
}

bool html_object::_parseName(TiXmlNode* node)
{
    assert(node != nullptr);
    const char* name = node->Value();
    if (name == nullptr)
    {
        return false;
    }
    m_name = name;
    return true;
}

bool html_object::_parseText(TiXmlElement* node)
{
    assert(node != nullptr);
    const char* text = node->GetText();
    if (text != nullptr)
    {
        m_text = CA2W(text, CP_UTF8).m_psz;
        return true;
    }
    return false;
}
