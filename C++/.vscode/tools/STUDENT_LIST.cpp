
#include "STUDENT_LIST.h"
/*------------------------------------------------------------------------
学生链表的成员函数的实现
------------------------------------------------------------------------*/
Status StudentList::Sort()
{
    ListPointer p = this->head->next, q = p->next, r;
    p->next = NULL;   //关闭
    while (q)
    {
        r = q;
        q = q->next;
        this->ListInsert_by_no(r->ele);
        delete r;
    }
    return OK;
}
Status StudentList::Update(int no, STUDENT* e)
{
    ListPointer p = this->head->next;
    int pos = 1;
    while (p && no != p->ele.get_no())
    {
        p = p->next;
        pos++;
    }
    if (p == NULL)
    {
        return ERROR;
    }
    p->ele = *e;
    return OK;
}
Status StudentList::GetElem_by_no(int no, STUDENT* e)
{
    ListPointer p = this->head->next;
    int pos = 1;
    while (p && no != p->ele.get_no())
    {
        p = p->next;
        pos++;
    }
    if (p == NULL)
    {
        return ERROR;
    }
    *e = p->ele;
    return OK;
}
Status StudentList::ListInsert_by_no(STUDENT e)
{
    ListPointer p = this->head, s;
    int pos = 0;
    //找到第小于e的最后一个位置
    while (p->next && e.get_no() > p->next->ele.get_no())
    {
        p = p->next;
        pos++;
    }

    //在p的位置处插入一个元素
    s = new NodeList;
    if (s == NULL)
        return LOVERFLOW;
    s->next = p->next;
    p->next = s;

    //赋值
    s->ele = e;
    return OK;
}
StudentList::StudentList()
{
    this->head = new NodeList;
    if (this->head == NULL)
    {
        //一般来说最好给全局变量赋值并退出
        exit(LOVERFLOW);
    }
    this->head->next = NULL;
}
StudentList::~StudentList()
{
    ListPointer p = this->head, q;
    //顺序消除
    do {
        q = p;
        p = p->next;
        delete q;
    } while (p);
}
Status StudentList::ClearList()
{
    ListPointer p = this->head->next, q;
    while (p)
    {
        q = p;
        p = p->next;
        delete q;
    }
    this->head->next = NULL;
    return OK;
}
Status StudentList::ListEmpty()
{
    if (head->next == NULL)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
int StudentList::ListLength()
{
    ListPointer p = this->head->next;
    int len = 0;
    while (p)
    {
        p = p->next;
        len++;
    }
    return len;
}
Status StudentList::GetElem(int pos, STUDENT* e)
{
    ListPointer p = this->head->next; //指向头结点
    int i;
    for (i = 1; i < pos && p; i++)
    {
        p = p->next;
    }
    if (p == NULL || i > pos)  //p=NULL即找不到了 i>pos即初始状态不合理
    {
        return ERROR;
    }
    *e = p->ele;
    return OK;
}
int StudentList::LocateElem(int no)
{
    ListPointer p = this->head->next;
    int pos = 1;
    while (p && no != int(p->ele))
    {
        p = p->next;
        pos++;
    }
    return p == NULL ? ERROR : pos;
}
Status StudentList::ListInsert(int pos, STUDENT e)
{
    ListPointer p = head, s;   //s用来申请新的节点
    /*
    //判断是否越界1
    int len=this->ListLength();
    if(!(pos>=1&&pos<=len+1))
        return ERROR;
    */
    int i = 0;    //初始位置是头结点

    //寻找第pos-1个节点
    while (p && i < pos - 1)   //这里只写p的原因是我只需要确定p是存在的，就可以在p后面添加内容
    {
        i++;
        p = p->next;
    }

    //判断错误
    if (p == NULL || i > pos - 1)
    {
        return ERROR;
    }

    //到这里为止p指向i-1个节点
    //申请新节点
    s = new NodeList;
    if (s == NULL)
    {
        return LOVERFLOW;
    }
    s->ele = e;   //赋值
    //维护链表
    s->next = p->next;
    p->next = s;
    return OK;
}
/*Status StudentList::ListDelete(int pos,STUDENT* e)
{
    ListPointer p=this->head,q;
    int i=0;


    //错误排除1
    //int len=this->ListLength();
    //if(!(pos>=1&&pos<=len))
    //{
    //    return ERROR;
    //}

    //寻找第pos-1个节点
    while(p->next&&i<pos-1) //这里写p->next的原因是要保证p的next必须可删除
    {
        i++;
        p=p->next;
    }

    //错误排除2  更加快速
    if(p->next==NULL||i>pos-1)
    {
        return ERROR;
    }

    //维护链表
    //此时p指向i-1
    q=p->next;
    p=q->next;

    *e=q->ele;
    delete q;
    return OK;
}
*/
Status StudentList::ListDelete(int no, STUDENT* e)
{
    ListPointer p = this->head, q;
    int pos = 0;
    //找到第i-1个位置
    while (p->next && no != int(p->next->ele))
    {
        p = p->next;
        pos++;
    }
    if (p->next == NULL)
    {
        return ERROR;
    }

    //维护
    q = p->next;
    p->next = q->next;

    //赋值并删除
    *e = q->ele;
    delete q;
    return OK;
}

