#include "UNIVERSAL_GENLIST.h"

/*------------------------------------------------------------------------
广义表的实现
------------------------------------------------------------------------*/
template<class T>
GenList<T>::GenList()
{
    this->head=new GenListNode; //申请头结点
    if(this->head==NULL)exit(-1);
}
template<class T>
GenList<T>::~GenList()
{

}
template<class T>
Status GenList<T>::Head(Element<T> &x)
{
    if(this->head->next==NULL)return ERROR;
    else
    {
        x=this->head->next->ele;
        return OK;
    }
}
template<class T>
Status GenList<T>::Tail(GenList<T> &lt)
{
    if(this->head->next==NULL)return ERROR; //空表的情况 没有尾
    else
    {
        lt.head->ele.utype=0;
        lt.head->ele.info.ref=0;
        lt.head->next=Copy(this->head->next->next);
        return OK;
    }
}
template<class T>
GenListNode<T>* GenList<T>::First()
{
    if(this->head->next==NULL)return ERROR;
    else
    {
        return this->head->next;
    }
    
}
template<class T>
GenListNode<T>* GenList<T>::Next(GenListNode<T> *nodepoint)
{
    //返回ele的直接后继
    if(nodepoint->next==NULL)return ERROR;
    else
    {
        return nodepoint->next;
    }
}
template<class T>
void GenList<T>::Copy(const GenList<T> &R)  //共有函数
{
    this->head=Copy(R.head);                //调用私有函数
}
template<class T>
GenListNode<T>* GenList<T>::Copy(GenListNode<T> *ls)
{
    GenListNode<T> *q;
    if(ls!=NULL)
    {
        q=new GenListNode<T>;
        if(q==NULL)return LOVERFLOW;    //申请空间失败，退出
        q->ele.utype=ls->ele.utype;
        switch(ls->ele.utype)
        {
            case(0):
            {
                q->ele->info.ref=ls->ele.info.ref;
                break;
            }
            case(1):
            {
                q->ele.info.value=ls->ele.info.value;
                break;
            }
            case(2):
            {
                q->ele.info.next=Copy(ls->ele.info.next);
                break;
            }
        }
        q->next=Copy(ls->next);     //处理同一层下一个节点为头的表
    }
    return q;
} 
template<class T>
int GenList<T>::Length()
{
    return this->Length(head);
}
template<class T>
int GenList<T>::Length(GenListNode<T> *ls)
{
    //私有函数，求以ls为表头的表的长度
    if(ls->next!=NULL)return 1+Length(ls->next);        //此处和书上不一样
    else return 0;
}
//暂时不做了 感觉用不到..





