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
        ///> 注册 CSS 尺寸属性（Dimension）
        CSS_ARRIBUTE_PARAM("width", width, css_convert_int_opt())
        CSS_ARRIBUTE_PARAM("height", height, css_convert_int_opt())
        CSS_ARRIBUTE_PARAM("max-width", max_width, css_convert_int_opt())
        CSS_ARRIBUTE_PARAM("min-width", min_width, css_convert_int_opt())
        CSS_ARRIBUTE_PARAM("max-height", max_height, css_convert_int_opt())
        CSS_ARRIBUTE_PARAM("min-height", min_height, css_convert_int_opt())
        ///> 注册 CSS 背景属性（Background）
        CSS_ARRIBUTE_PARAM("background-color", background_color, css_convert_color_opt())
    CSS_ARRIBUTE_LIST_END()

public:
    ///> 注册 CSS 尺寸属性（Dimension）
    int                     width;
    int                     height;
    int                     max_width;
    int                     min_width;
    int                     max_height;
    int                     min_height;
    ///> 注册 CSS 背景属性（Background）
    //int background;                       ///>在一个声明中设置所有的背景属性。
    int                     background_attachment;            ///>设置背景图像是否固定或者随着页面的其余部分滚动。
    tid::uint32             background_color;                 ///>设置元素的背景颜色。
    std::wstring            background_image;                 ///>设置元素的背景图像。
    int                     background_position;              ///>设置背景图像的开始位置。
    int                     background_repeat;                ///>设置是否及如何重复背景图像。
    int                     background_clip;                  ///>规定背景的绘制区域。
    int                     background_origin;                ///>规定背景图片的定位区域。
    int                     background_size;                  ///>规定背景图片的尺寸。
};

#endif // __CSS_ARRIBUTE_H_