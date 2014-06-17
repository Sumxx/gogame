/* -------------------------------------------------------------------------
//  File        :   draw_object_factory.h
//  Author      :   Sum
//  Datet       :   2014/6/16 23:49
//  Brief       :   
//
// -----------------------------------------------------------------------*/
#ifndef __DRAW_OBJECT_FACTORY_H_
#define __DRAW_OBJECT_FACTORY_H_

#include "html_object.h"
#include "draw_head.h"

#define  DRAW_OBJECT_FACTORY_REGISTER(createName, nameObject, classname) \
if (createName == nameObject) \
{ return new classname; } \

class draw_object_factory
{
public:
    static interface_draw_object* createObject(const std::string& name)
    {
        if (name.empty())
        {
            return nullptr;
        }
        return _factory(name);
    }

    static interface_draw_object* createObject(html_object* object)
    {
        if (object == nullptr)
        {
            return nullptr;
        }
        return draw_object_factory::createObject(object->m_name);
    }

    static bool                   deleteObject(interface_draw_object* object)
    {
        if (object != nullptr)
        {
            delete object;
            object = nullptr;
        }
        return true;
    }

private:
    static interface_draw_object* _factory(const std::string& name)
    {
        DRAW_OBJECT_FACTORY_REGISTER(name, "head", draw_head);
        return nullptr;
    }
};

#endif // __DRAW_OBJECT_FACTORY_H_