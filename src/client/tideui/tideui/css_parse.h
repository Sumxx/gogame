/* -------------------------------------------------------------------------
//  File        :   css_parse.h
//  Author      :   Sum
//  Datet       :   2014/6/9 16:08
//  Brief       :   
//
// -----------------------------------------------------------------------*/
#ifndef __CSS_PARSE_H_
#define __CSS_PARSE_H_

#include "css_object.h"
#include <vector>
#include <fstream>

class css_parse
{
public:
    css_parse();
    virtual ~css_parse();

public:
    virtual bool                parseFile(const std::wstring& filePath);
    virtual bool                parseBuffer(void* bufferPtr, int bufferLen);

private:
    bool                        _parseCSS(char* bufferPtr, int bufferLen);
    int                         _parseNode(css_objcet* object, char* bufferPtr, int bufferLen, int presentIndex);
    int                         _parseAttr(css_objcet* object, char* bufferPtr, int bufferLen, int presentIndex);
    bool                        _isNameEnd(char* bufferPtr, int bufferLen, int presentIndex);
    bool                        _isArrEnd(char* bufferPtr, int bufferLen, int presentIndex);
    long                        _getFileLen(std::fstream& fileStream);
    int                         _isNameStart(char c);
    int                         _isNameChar(char c);
    int                         _isOperator(char c);

public:
    typedef std::vector<css_objcet*> _cssObjectInfo;

public:
    _cssObjectInfo              m_cssObjectInfoVec;
};

#endif // __CSS_PARSE_H_