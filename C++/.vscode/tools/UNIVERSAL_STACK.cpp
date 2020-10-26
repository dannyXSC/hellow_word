#include "UNIVERSAL_STACK.h"

/*------------------------------------------------------------------------
基本类型的通用链式栈的实现
------------------------------------------------------------------------*/
template<class T>
LinkedStack<T>::LinkedStack()
{
    //申请头结点
    this->top=new Node<T>;
    if(this->top==NULL)exit(LOVERFLOW);
    //初始化在Node中写过了
}
template<class T>
void LinkedStack<T>::MakeEmpty()
{
    Node<T> *p=this->top,*q;
    while(p)
    {
        q=p;
        p=p->Next;
        delete q;
    }
}
template<class T>
void LinkedStack<T>::Push(const T& x)
{
    Node<T> *s=new Node<T>(x);
    if(s==NULL)exit(LOVERFLOW);
    //连上
    s->Next=this->top->Next;
    this->top->Next=s;
}
template<class T>
Status LinkedStack<T>::Pop(T& x)
{
    //如果是空表 返回错误
    if(this->top==NULL||this->top->Next==NULL)return ERROR;
    //赋值
    x=this->top->Next->element;
    //删除节点
    Node<T> *p=this->top->Next;
    this->top->Next=p->Next;
    delete p;
    return OK;
}
template<class T>
Status LinkedStack<T>::GetTop(T& x)const
{
    if(this->top==NULL||this->top->Next==NULL)return ERROR;
    //赋值
    x=this->top->Next->element;
    return OK;
}
template<class T>
Status LinkedStack<T>::IsEmpty()const
{
    if(this->top==NULL||this->top->Next==NULL)return YES;
    else return NO;
}
template<class T>
int LinkedStack<T>::GetSize()const
{
    Node<T> *p=this->top->Next;
    int cnt=0;
    while(p!=NULL)
    {
        cnt++;
        p=p->Next;
    }
    return cnt;
}
template<class T>
void LinkedStack<T>::DisplayStack()
{
    Node<T> *p=this->top->Next;
    while(p)
    {
        if(p->Next==NULL)
        {
            printf("<%d>\n",p->element);
        }
        else
        {
            printf("<%d>-->",p->element);
        }
        p=p->Next;
    }
}


const int arr[]={9,8,7,6,5,4,3,2,1,100,-1};

int main()
{
    //test
    LinkedStack<int> sk;
    for(int i=0;arr[i]!=-1;i++)
    {
        sk.Push(arr[i]);
    }
    sk.DisplayStack();
    cout<<endl;
    for(int i=0;arr[i]!=-1;i++)
    {
        int a;
        sk.Pop(a);
    }
    sk.DisplayStack();
    cout<<endl;
}
