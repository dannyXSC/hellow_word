#include "UNIVERSAL_QUEUE.h"
/*------------------------------------------------------------------------
基本类型的通用链表的实现
------------------------------------------------------------------------*/
template<class T>
LinkedQueue<T>::LinkedQueue()
{
    Node<T> *s=new Node<T>;  //申请头结点 next为null
    if(s==NULL)exit(LOVERFLOW); //如果申请不成功，退出
    this->head=s;   //头指针指向s
    this->end=s;    //尾指针指向s
}
template<class T>
void LinkedQueue<T>::makeEmpty()
{
    Node<T>* p=this->head,*q;
    while(p!=NULL)
    {
        q=p;
        p=p->Next;
        delete q;
    }
}
template<class T>
Status LinkedQueue<T>::EnQueue(const T& x)
{
    //加入到尾结点之后
    Node<T>* s=new Node<T>(x); //申请一个新节点,值为x，next为null
    if(s==NULL)exit(LOVERFLOW); //如果申请不成功，退出
    this->end->Next=s;
    this->end=s;
    return OK;
}
template<class T>
Status LinkedQueue<T>::DeQueue(T& x)
{
    if(this->IsEmpty()==YES)return ERROR;
    //如果非空 删除第一个节点
    Node<T> *p=this->head,*q=p->Next;
    x=q->element;
    p->Next=q->Next;
    delete q;
}
template<class T>
Status LinkedQueue<T>::GetFront(T& x)
{
    if(this->IsEmpty()==YES)return ERROR;
    //非空 返回第一个节点的值
    x=this->head->Next->element;
    return OK;
}
template<class T>
Status LinkedQueue<T>::IsEmpty()const
{
    if(this->head->Next==NULL)return YES;
    else {return NO;}
}
template<class T>
int LinkedQueue<T>::GetSize()const
{
    Node<T> *p=this->head->Next;
    int cnt=0;
    while(p!=NULL)
    {
        cnt++;
        p=p->Next;
    }
    return cnt;
}

