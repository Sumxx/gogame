/* -------------------------------------------------------------------------
//  File        :   freedom_script.h
//  Author      :   Sum
//  Datet       :   2014/5/12 0:59
//  Brief       :   
//
// -----------------------------------------------------------------------*/
#ifndef __FREEDOM_SCRIPT_H_
#define __FREEDOM_SCRIPT_H_

#include <vector>
#include "tinyxml/tinyxml.h"
#include "interface_freedom_script.h"
#include "freedom_control_object_base.h"

class freedom_script : public i_freedom_script
{
public:
    freedom_script();
    ~freedom_script();

public:
    bool                         parseScriptFile(const std::wstring& filePath);
    bool                         parseBuffer(void* bufferPtr, int bufferLen);
    int                          getControlNum();

    freedom_control_object_base* getBeineObject();
    freedom_control_object_base* getNextObject();
    freedom_control_object_base* getEndObject();

private:
    typedef std::vector<freedom_control_object_base*> _controlPoolType;

private:
    bool                         _parse(TiXmlDocument& doc);
    bool                         _parseHead(TiXmlElement* rootElement);
    bool                         _parseBody(TiXmlElement* rootElement);
    bool                         _parseBaseElement(TiXmlElement* prentsElement);
    freedom_control_object_base* _productionObject(TiXmlElement* prentsElement);

private:
    _controlPoolType        m_controlPoolHead;
};

#endif // __FREEDOM_SCRIPT_H_