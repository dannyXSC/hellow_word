#pragma once
#include "HEADFILES.h"
/*------------------------------------------------------------------------
menu的声明
------------------------------------------------------------------------*/
/*宏定义和常变量*/
static const int Unit_width = 30; //菜单的基本宽度为30

//声明
class SIMPLE_MENU {
private:
    const char** menu;  //menu必须在构造函数中初始化menu应该是指向 指向常量的指针 的指针
    int width;  //每个菜单项的宽度

    bool if_sensitive;  //标志 可选项中是否敏感大小写
    const char* key;    //可选择项

    bool if_exist_title;    //标志 是否有标题
    const char* title;  //存储标题内容 

    bool if_exist_order;    //标志 是否有提示
    const char* order;  //储存 提示(order)

    int item_nums;  //menu中有多少个条目

    const char* border; //边框的符号

    /*暂时不用*/
    int arrangement;  //0表示从上到下1表示从左到右
    int col;    //表示多列显示

public:
    SIMPLE_MENU(const char** menu, bool if_sensitive = false, bool if_exist_title = false,
        bool if_exist_order = false, const char* key = "", const char* title = "",
        const char* order = "", const char* border = "=", int width = Unit_width);
    ~SIMPLE_MENU() {}
    friend void wait_for_end(const char* prompt, const char* key);
    const char display_menu();  //输出表
    const char* get_menuitem(const char sel);   //查看menu中是否有sel,并返回
};