#include "SIMPLE_TOOLS_MENU.h"

/*------------------------------------------------------------------------
menu的成员函数的实现
------------------------------------------------------------------------*/
SIMPLE_MENU::SIMPLE_MENU(const char** menu, bool if_sensitive, bool if_exist_title,
    bool if_exist_order, const char* key, const char* title,
    const char* order, const char* border, int width)
    :menu(menu), width(width), if_sensitive(if_sensitive), key(key),
    if_exist_title(if_exist_title), title(title), if_exist_order(if_exist_order),
    border(border), order(order)    //初始化表
{
    //在构造函数中计算item的项目节省时间
    int cnt = 0;
    while (menu[cnt])cnt++;
    this->item_nums = cnt;

    //暂时不用的私有变量
    this->arrangement = 0;
    this->col = 1;
};
const char* SIMPLE_MENU::get_menuitem(const char sel)
{
    int i;
    for (i = 0; menu[i]; i++)
        if (this->menu[i][0] == sel) //每个菜单字符串的第[0]个字符是否选择项
            return menu[i];

    return NULL;
};
const char SIMPLE_MENU::display_menu()
{
    char sel;
    int i, j;
    int loop = 1;
    cout << setiosflags(ios::left);   //左对齐
    while (loop)
    {
        if (this->if_exist_title)    //输出标题
        {
            cout << title << endl;
        }
        for (i = 1; i <= col * this->width; i++)
        {
            cout << this->border;
        }
        cout << endl;
        for (i = 0; arrangement && menu[i];)
        {
            for (j = 1; j <= col && menu[i]; j++, i++)
                cout << setw(this->width) << menu[i];
            cout << endl;
        }
        for (i = 0; !arrangement && i < (this->item_nums + col - 1) / col; i++)             //可能有点问题
        {
            for (j = 0; j < col && menu[i + j * (this->item_nums / col) + (j > this->item_nums % col ? this->item_nums % col : j)]; j++)
                cout << setw(this->width) << menu[i + j * (this->item_nums / col) + (j > this->item_nums % col ? this->item_nums % col : j)];
            cout << endl;
        }
        for (i = 1; i <= col * this->width; i++)
        {
            cout << this->border;
        }
        cout << endl;

        if (this->if_exist_order)
        {
            cout << "请选择[" << this->order << "] : ";
        }
        else
        {
            cout << "请选择:";
        }
        sel = _getche();
        cout << endl;
        for (i = 0; key[i]; i++)
            if (sel == key[i])
            {
                loop = 0;
                break;
            }
        /* 选择错误则给出提示并再次打印菜单 */
        if (loop)
            cout << endl << endl << "输入错误，请重新选择" << endl << endl;
    }
    if (sel >= 'a' && sel <= 'z' && !this->if_sensitive)
        sel = sel - 'a' + 'A';
    return sel;
}

