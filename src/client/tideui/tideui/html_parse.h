/* -------------------------------------------------------------------------
//  File        :   html_parse.h
//  Author      :   Sum
//  Datet       :   2014/6/2 2:43
//  Brief       :   
//
// -----------------------------------------------------------------------*/
#ifndef __HTML_PARSE_H_
#define __HTML_PARSE_H_

#include "tinyxml\tinyxml.h"
#include "html_object.h"
#include <string>
#include <vector>

class html_parse
{
public:
    html_parse();
    virtual ~html_parse();

public:
    virtual bool                parseFile(const std::wstring& filePath);
    virtual bool                parseBuffer(void* bufferPtr, int bufferLen);

private:
    bool                        _parseHtmlFile(const std::wstring& filePath);
    bool                        _parseBuffer(void* bufferPtr, int bufferLen);
    bool                        _parse(TiXmlDocument& doc);

public:
    typedef std::vector<html_object*>    htmlElement;

private:
    htmlElement                m_htmlElement;
};

#endif // __HTML_PARSE_H_