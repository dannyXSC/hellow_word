#pragma once

/*input*/
void safe_cin_positive_integer(int& x, const char* tips);   //安全输入一个正整数

/*menu*/
#include "SIMPLE_TOOLS_MENU.h"  //菜单

/*wait*/
void wait_for_end(const char* prompt, const char* key); //等待输入一个字符串以结束(不区分大小写)
void wait_for_enter();                                  //等待输入回车以结束