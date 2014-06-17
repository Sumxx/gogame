/* -------------------------------------------------------------------------
//  File        :   css_parse.cpp
//  Author      :   Sum
//  Datet       :   2014/6/9 16:10
//  Brief       :   
//
// -----------------------------------------------------------------------*/
//
#include "stdafx.h"
#include "css_parse.h"
#include <assert.h>
#include <mutex>

css_parse::css_parse()
{

}

css_parse::~css_parse()
{

}

bool css_parse::parseFile(const std::wstring& filePath)
{
    if (filePath.empty())
    {
        return false;
    }

    bool returnValue = false;
    char* bufferPtr = nullptr;
    std::fstream fileStream;
    do 
    {
        fileStream.open(filePath);
        if (!fileStream.is_open())
        {
            break;
        }

        long fileLength = _getFileLen(fileStream);
        bufferPtr = new char[fileLength + 1];
        if(bufferPtr == nullptr)
        {
            break;
        }

        ::memset(bufferPtr, 0, fileLength + 1);
        if (fileStream.read(bufferPtr, fileLength).gcount() == 0)
        {
            break;
        }

        returnValue = _parseCSS((char*)bufferPtr, fileLength);
    } while (false);

    if (bufferPtr != nullptr)
    {
        delete[] bufferPtr;
        bufferPtr = nullptr;
    }
    fileStream.close();
    return returnValue;
}

bool css_parse::parseBuffer(void* bufferPtr, int bufferLen)
{
    return true;
}

bool css_parse::_parseCSS(char* bufferPtr, int bufferLen)
{
    assert(bufferPtr != nullptr);
    for (int index = 0; index < bufferLen; ++index)
    {
        if (_isWhitespace(bufferPtr[index])
            || _isNonAscii(bufferPtr[index]))
        {
            continue;
        }
        if (_isAlpha(bufferPtr[index])
            || _isOperator(bufferPtr[index]))
        {
            css_objcet* cssObject = new css_objcet;
            if (cssObject == nullptr)
            {
                break;
            }

            index = _parseNode(cssObject, bufferPtr, bufferLen, index);
            m_cssObjectInfoVec.push_back(cssObject);
        }
    }
    return true;
}

long css_parse::_getFileLen(std::fstream& fileStream)
{
    long length = 0;
    fileStream.seekg(0, std::ios::end);
    length = (long)fileStream.tellg();
    fileStream.seekg(std::ios::beg);
    return length;
}

int css_parse::_isNonAscii(char c)
{
    return ((c >= 0x80 && c <= 0xD7FF)
        || (c >= 0xE00 && c <= 0xFFFD)
        || (c >= 0x10000 && c <= 0x10FFFF));
}

int css_parse::_isHex(char c)
{
    return ((c >= '0' && c <= '9')
        || (c >= 'a' && c <= 'f')
        || (c >= 'A' && c <= 'F'));
}

int css_parse::_isUrlChar(char c)
{
    return ((c == 0x9
        || c == 0x21
        || (c >= 0x23 && c <= 0x26 )
        || (c >= 0x27 && c <= 0x7E )
        || _isNonAscii( c ))
        && c != ')');
}

int css_parse::_isStringChar(char c)
{
    return (_isUrlChar( c )
        || c == 0x20);
}

int css_parse::_isNewline(char c)
{
    return (c == 0xA
        || c == 0xD
        || c == 0xC);
}

int css_parse::_isWhitespace(char c)
{
    return (_isNewline(c)
        || c == 0x9
        || c == 0x20);
}

int css_parse::_isNameChar(char c)
{
    return (iswalpha(c)
        || iswdigit(c)
        || c == '-'
        || c == '_'
        || _isNonAscii(c));
}

int css_parse::_isNameStart(char c)
{
    return (iswalpha(c)
        || c == '_'
        || _isNonAscii(c));
};

int css_parse::_isAlpha(char c)
{
    return iswalpha(c);
}

int css_parse::_isNumeric(char c)
{
    return (iswdigit(c));
}

int css_parse::_isAlphanumeric(char c)
{
    return iswalnum(c);
}

int css_parse::_isQuote(char c)
{
    return (c == '"'
        || c == '\'');
}
int css_parse::_isOperator(char c)
{
    switch (c)
    {
    case '~':
    case '|':
    case '^':
    case ':':
    case ';':
    case '{':
    case '}':
    case '[':
    case ']':
    case '@':
    case '#':
    case '.':
    case '(':
    case ')':
        return 1;
    }
    return 0;
}

int css_parse::_parseNode(css_objcet* object, char* bufferPtr, int bufferLen, int presentIndex)
{
    assert(bufferPtr != nullptr);
    assert(object != nullptr);

    std::string name;
    css_name cssName;
    int index = presentIndex;
    for (; index < bufferLen; ++index)
    {
        if (_isWhitespace(bufferPtr[index]))
        {
            if (bufferPtr[index] == ' '
                && !name.empty()
                && !_isNameEnd(bufferPtr, bufferLen, index))
            {
                cssName.relationList.push_back(name);
                name.clear();
            }
            continue;
        }
        if (_isAlpha(bufferPtr[index])
            || _isNameChar(bufferPtr[index])
            || bufferPtr[index] == '.'
            || bufferPtr[index] == '#'
            || bufferPtr[index] == '@')
        {
            name += bufferPtr[index];
        }
        if (bufferPtr[index] == ',')
        {
            if (!name.empty())
            {
                cssName.nameList.push_back(name);
            }
            object->cssGroup.push_back(cssName);
            cssName.nameList.clear();
            cssName.relationList.clear();
            name.clear();
        }
        if (bufferPtr[index] == '{')
        {
            if (!name.empty())
            {
                cssName.nameList.push_back(name);
                name.clear();
            }
            object->cssGroup.push_back(cssName);
            cssName.nameList.clear();
            cssName.relationList.clear();
            index = _parseAttr(object, bufferPtr, bufferLen, index);
        }
        if (bufferPtr[index] == '}')
        {
            break;
        }
    }
    return index;
}

int css_parse::_parseAttr(css_objcet* object, char* bufferPtr, int bufferLen, int presentIndex)
{
    assert(bufferPtr != nullptr);
    assert(object != nullptr);

    std::string attrName;
    std::string attrValue;
    bool isSetValue = false;
    int index = presentIndex;
    for (; index < bufferLen; ++index)
    {
        if (_isWhitespace(bufferPtr[index]))
        {
            if (bufferPtr[index] == ' '
                && !attrName.empty()
                && !attrValue.empty()
                && !_isArrEnd(bufferPtr, bufferLen, index))
            {
                object->cssArrMap[attrName].push_back(attrValue);
                attrValue.clear();
            }
            continue;
        }
        if (bufferPtr[index] == ':')
        {
            isSetValue = true;
        }
        if (bufferPtr[index] == ';')
        {
            object->cssArrMap[attrName].push_back(attrValue);
            attrValue.clear();
            attrName.clear();
            isSetValue = false;
        }
        if (_isAlpha(bufferPtr[index])
            || _isNumeric(bufferPtr[index])
            || bufferPtr[index] == '/'
            || bufferPtr[index] == '\\'
            || bufferPtr[index] == '.'
            || bufferPtr[index] == '#'
            || bufferPtr[index] == '('
            || bufferPtr[index] == ')')
        {
            if (isSetValue)
            {
                attrValue += bufferPtr[index];
            }
            else
            {
                attrName += bufferPtr[index];
            }
        }
        if (bufferPtr[index] == '}')
        {
            if (!attrName.empty())
            {
                object->cssArrMap[attrName].push_back(attrValue);
            }
            break;
        }
    }
    return index;
}

bool css_parse::_isNameEnd(char* bufferPtr, int bufferLen, int presentIndex)
{
    assert(bufferPtr != nullptr);

    int index = presentIndex;
    for (; index < bufferLen; ++index)
    {
        if (_isWhitespace(bufferPtr[index]))
        {
            continue;
        }
        if (_isAlpha(bufferPtr[index])
            || _isNumeric(bufferPtr[index]))
        {
            return false;
        }
        if (bufferPtr[index] == '{'
           || bufferPtr[index] == ',')
        {
            break;
        }
    }
    return true;
}

bool css_parse::_isArrEnd(char* bufferPtr, int bufferLen, int presentIndex)
{
    assert(bufferPtr != nullptr);

    int index = presentIndex;
    for (; index < bufferLen; ++index)
    {
        if (_isWhitespace(bufferPtr[index]))
        {
            continue;
        }
        if (_isAlpha(bufferPtr[index])
            || _isNumeric(bufferPtr[index]))
        {
            return false;
        }
        if (bufferPtr[index] == '}'
            || bufferPtr[index] == ';')
        {
            break;
        }
    }
    return true;
}
