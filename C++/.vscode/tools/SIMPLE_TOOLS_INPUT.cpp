#include "HEADFILES.h"
/*------------------------------------------------------------------------
函数名  :safe_cin_positive_integer
功能    :安全输入一个正整数
参数    :x 需要输入的变量
        tips 问题提示语
------------------------------------------------------------------------*/
void safe_cin_positive_integer(int& x, const char* tips,int toplimit=0x7fffffff)    //默认上限为int最大值
{
    cout << tips;
    while (1)    //考虑一部分输入错误问题
    {
        if (scanf("%d", &x) != 1)
        {
            cout << "输入错误请重新输入" << endl;
            getchar();
            while (getchar() != '\n');
        }
        else if (x <= 0)
        {
            cout << "输入错误请重新输入" << endl;
        }
        else if(x>toplimit)
        {
            cout<<"输入超过上限("<<toplimit<<")请重新输入"<<endl;
        }
        else
        {
            break;
        }
        cout << tips;
    }
}
/*------------------------------------------------------------------------
函数名  :safe_cin_string
功能    :安全输入一个string
参数    :x 需要输入的变量
        tips 问题提示语
------------------------------------------------------------------------*/
void safe_cin_string(string &x, const char* tips)
{
    cout<<tips;
    cin>>x;
    return;
}
