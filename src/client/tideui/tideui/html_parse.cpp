/* -------------------------------------------------------------------------
//  File        :   html_parse.cpp
//  Author      :   Sum
//  Datet       :   2014/6/2 2:47
//  Brief       :   
//
// -----------------------------------------------------------------------*/
//
#include "stdafx.h"
#include "html_parse.h"

html_parse::html_parse()
{
}

html_parse::~html_parse()
{
}

bool html_parse::parseFile(const std::wstring& filePath)
{
    if (filePath.empty())
    {
        return false;
    }
    return _parseHtmlFile(filePath);
}

bool html_parse::parseBuffer(void* bufferPtr, int bufferLen)
{
    if (bufferPtr == nullptr
        || bufferLen == 0)
    {
        return false;
    }
    return _parseBuffer(bufferPtr, bufferLen);
}

bool html_parse::_parseBuffer(void* bufferPtr, int bufferLen)
{
    return true;
}

bool html_parse::_parseHtmlFile(const std::wstring& filePath)
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

bool html_parse::_parse(TiXmlDocument& doc)
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

    for (TiXmlNode* nodeRoot = rootElement->FirstChildElement();
        nodeRoot != nullptr;
        nodeRoot = nodeRoot->NextSiblingElement())
    {
        html_object* object = new html_object;
        if (!object)
        {
            continue;
        }

        if (object->parse(nodeRoot))
        {
            m_htmlElement.push_back(object);
        }
    }
    return true;
}
