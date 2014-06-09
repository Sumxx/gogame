/* -------------------------------------------------------------------------
//  File        :   interface_freedom_script.h
//  Author      :   Sum
//  Datet       :   2014/5/12 0:28
//  Brief       :   
//
// -----------------------------------------------------------------------*/
#ifndef __INTERFACE_FREEDOM_SCRIPT_H_
#define __INTERFACE_FREEDOM_SCRIPT_H_

#include <string>
#include "freedom_control_object.h"

__interface i_freedom_script
{
    virtual bool                    parseScriptFile(const std::wstring& filePath) = 0;
    virtual bool                    parseBuffer(void* bufferPtr, int bufferLen) = 0;
    virtual int                     getControlNum() = 0;

    virtual freedom_control_object* getBeineObject() = 0;
    virtual freedom_control_object* getNextObject() = 0;
    virtual freedom_control_object* getEndObject() = 0;
};

#endif // __INTERFACE_FREEDOM_SCRIPT_H_