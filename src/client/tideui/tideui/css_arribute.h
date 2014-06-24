/* -------------------------------------------------------------------------
//  File        :   css_arribute.h
//  Author      :   Sum
//  Datet       :   2014/6/22 12:47
//  Brief       :   
//
// -----------------------------------------------------------------------*/
#ifndef __CSS_ARRIBUTE_H_
#define __CSS_ARRIBUTE_H_

#include <map>
#include <string>
#include <vector>
#include "css_convert.h"

#define CSS_ARRIBUTE_LIST_BEGIN() \
bool _setValue(const cssObjectArrtibute& arribute) \
{ \
    for (auto it = arribute.begin(); \
        it != arribute.end(); \
        ++it) \
    {

#define CSS_ARRIBUTE_PARAM(name, saveValue, fun) \
if (_stricmp(it->first.c_str(), name) == 0) \
{ \
    for (std::string cssValue : it->second) \
    { \
        saveValue = fun(cssValue.c_str()); \
        break; \
    } \
    continue; \
}

#define CSS_ARRIBUTE_PARAM_NOTFUN(name, saveValue) \
    if (_stricmp(it->first.c_str(), name) == 0) \
{ \
    for (std::string cssValue : it->second) \
    { \
        saveValue = cssValue; \
        break; \
    } \
    continue; \
}

#define CSS_ARRIBUTE_LIST_END() \
    } \
return true; \
}

typedef std::map<std::string, std::vector<std::string> > cssObjectArrtibute;

class css_arribute
{
public:
    css_arribute();
    virtual ~css_arribute();

public:
    virtual bool                set(const cssObjectArrtibute& arribute);
    virtual bool                clear();

private:
    CSS_ARRIBUTE_LIST_BEGIN()
        ///> ע�� CSS �ߴ����ԣ�Dimension��
        CSS_ARRIBUTE_PARAM("width", width, css_convert_int_opt())
        CSS_ARRIBUTE_PARAM("height", height, css_convert_int_opt())
        CSS_ARRIBUTE_PARAM("max-width", max_width, css_convert_int_opt())
        CSS_ARRIBUTE_PARAM("min-width", min_width, css_convert_int_opt())
        CSS_ARRIBUTE_PARAM("max-height", max_height, css_convert_int_opt())
        CSS_ARRIBUTE_PARAM("min-height", min_height, css_convert_int_opt())
        ///> ע�� CSS �������ԣ�Background��
        CSS_ARRIBUTE_PARAM("background-color", background_color, css_convert_color_opt())
    CSS_ARRIBUTE_LIST_END()

public:
    ///> ע�� CSS �ߴ����ԣ�Dimension��
    int                     width;
    int                     height;
    int                     max_width;
    int                     min_width;
    int                     max_height;
    int                     min_height;
    ///> ע�� CSS �������ԣ�Background��
    //int background;                       ///>��һ���������������еı������ԡ�
    int                     background_attachment;            ///>���ñ���ͼ���Ƿ�̶���������ҳ������ಿ�ֹ�����
    tid::uint32             background_color;                 ///>����Ԫ�صı�����ɫ��
    std::wstring            background_image;                 ///>����Ԫ�صı���ͼ��
    int                     background_position;              ///>���ñ���ͼ��Ŀ�ʼλ�á�
    int                     background_repeat;                ///>�����Ƿ�����ظ�����ͼ��
    int                     background_clip;                  ///>�涨�����Ļ�������
    int                     background_origin;                ///>�涨����ͼƬ�Ķ�λ����
    int                     background_size;                  ///>�涨����ͼƬ�ĳߴ硣
};

#endif // __CSS_ARRIBUTE_H_