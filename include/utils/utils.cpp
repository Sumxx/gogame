#include "stdafx.h"
#include "utils.h"
#include <cstdio>

namespace utils
{

bool utils::GetXmlStrAttributeA( TiXmlElement *pElement, char *pName, std::string &strData )
{
    if (pElement)
    {
        const char *pStr = pElement->Attribute(pName);
        if (pStr)
        {
            strData = std::string(pStr);
            return true;
        }
    }
    return false;
}
bool utils::GetXmlIntAttribute( TiXmlElement *pElement, char *pName, int &nData )
{
    if (pElement)
    {
        const char *pStr = pElement->Attribute(pName);
        if (pStr)
        {
                nData = atoi(pStr);
                return true;
        }
    }
    return false;
}

CString GetGamePath()
{
    CString csReturnPath;
    WCHAR szFilePath[MAX_PATH] = {0};
    ::GetModuleFileNameW(0, szFilePath, MAX_PATH);
    ::PathRemoveFileSpecW(szFilePath);
    csReturnPath = szFilePath;
    csReturnPath += L"\\";
    return csReturnPath;
}

}