/* -------------------------------------------------------------------------
//  File        :   html_object.h
//  Author      :   Sum
//  Datet       :   2014/6/2 3:05
//  Brief       :   
//
// -----------------------------------------------------------------------*/
#ifndef __HTML_OBJECT_H_
#define __HTML_OBJECT_H_

#include "tinyxml\tinyxml.h"
#include <string>
#include <vector>
#include <map>

class html_object
{
public:
    html_object();
    virtual ~html_object();

public:
    bool                parse(TiXmlNode* node);
    bool                parseArrtibute(TiXmlElement* node);

private:
    typedef std::map<std::string, std::string> _objectArribute;
    typedef std::vector<html_object*>          _objectChiledNode;

private:
    bool                _parseElement(TiXmlNode* node);
    bool                _parseArrtibute(TiXmlNode* node);
    bool                _parseName(TiXmlNode* node);
    bool                _parseText(TiXmlElement* node);

private:
    _objectArribute           m_arributeMap;
    _objectChiledNode         m_chiledNodeVec;
    std::string               m_name;
    std::wstring              m_text;
};

#endif // __HTML_OBJECT_H_