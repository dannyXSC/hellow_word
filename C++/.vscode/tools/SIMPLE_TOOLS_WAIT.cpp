#include "HEADFILES.h"
/*------------------------------------------------------------------------
函数名  :wait_for_end
功能    :等待输入一个字符串以结束(不区分大小写)
参数    :prompt 提示语
        key 结束标准字符串
------------------------------------------------------------------------*/
void wait_for_end(const char* prompt, const char* key)
{
    char input_str[1024];

    while (1) {
        cout << prompt;
        cin >> input_str;

        /* 清空缓冲区 */
        cin.clear();
        cin.ignore(1024, '\n');
        //		fgets(input_str, sizeof(input_str), stdin);

                /* 输入在合理范围内则退出输入循环 */
        if (_strcmpi(input_str, key) == 0)
            break;
    }

    return;
}
/*------------------------------------------------------------------------
函数名  :wait_for_enter
功能    :等待输入回车以结束
参数    :
------------------------------------------------------------------------*/
void wait_for_enter()
{
    cout<<"请输入回车继续"<<endl;
    getchar();
    while(getchar()!='\n')
    ;
}