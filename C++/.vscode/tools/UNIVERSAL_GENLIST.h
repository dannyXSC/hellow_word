#pragma once
#include "HEADFILES.h"
/*------------------------------------------------------------------------
广义表
------------------------------------------------------------------------*/
//定义返回值
typedef int Status;
#define YES 1
#define NO 0
#define OK 1
#define ERROR 0
#define LOVERFLOW -1 
#define INFEASIBLE -2
#define TRUE 1
#define FALSE 0


/*------------------------------------------------------------------------
广义表节点的元素
------------------------------------------------------------------------*/
template <class T>
class Element{ //广义表结点的元素
public:
    int utype;  //   =0/1/2分别表示为广义表专用的附加头结点/原子节点/子表节点
    union{      //联合
        int ref;                         //referance  utype=0 附加头结点 存放引用计数
        T value;                         //           utype=1 原子节点   存放数值
        GenListNode<T> *next;            //utype=2 小节点     存放指向子表的指针
    }info;
    Element():utype(0),info.ref(0){} //构造函数
    Element(Element<T> &ele){this->info=ele.info;this->utype=ele.utype;}
                                    //复制构造函数
    Element<T>& operator=(Element<T> &ele){this->info=ele.info;this->utype=ele.utype;return *this;}
                                    //=重载
};


/*------------------------------------------------------------------------
广义表的节点
------------------------------------------------------------------------*/
template<class T>
class GenListNode{
protected:
    Element<T> ele;
    GenListNode<T> *next;
public:
    GenListNode():ele(),next(NULL){}    //构造函数
    GenListNode(GenListNode<T> &GLN){this->ele=GLN.ele;this->next=GLN.next;}
};


/*------------------------------------------------------------------------
广义表
------------------------------------------------------------------------*/
template<class T>
class GenList{
private:
    GenListNode<T> *head;
    GenListNode<T>* Copy(GenListNode<T> *node); //复制一个node指示的无共享非递归表
    int Length(GenListNode<T> *ls); //求长度
    int depth(GenListNode<T> *ls);  //求深度
    Status is_equal(GenListNode<T> *s,GenListNode<T> *t);    //判断两个表是否相等
    void Remove(GenListNode<T> *ls);    //释放以ls为附加头结点的广义表
    void Createlist(istream& in,GenListNode<T>* &ls);   
        //从输入流对象输入广义表的字符串描述，建立一个带附加头结点的广义表结构
public:
    GenList();                                          //构造
    ~GenList();                                         //析构
    Status Head(Element<T> &x);                            //返回表头元素x
    Status Tail(GenList<T> &lt);                        //返回表尾lt
    GenListNode<T> *First();                            //返回第一个元素
    GenListNode<T> *Next(GenListNode<T> *nodepoint);    //返回表元素ele的直接后继元素
    void Copy(const GenList<T> &R);                     //广义表的复制
    int Length();                                       //计算广义表的长度
    int depth();                                        //计算一个非递归表的深度
};












