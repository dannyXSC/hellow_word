#pragma once
#include "HEADFILES.h"

/*------------------------------------------------------------------------
基本类型的通用链式栈
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

//节点
template<class T>
struct Node{        
    T element;  //元素 只要重定义了=的类型就可以使用
    Node<T>* Next;  //指针 指向下一个Node
    Node(Node<T>* ptr=NULL){this->Next=ptr;}    //空初始化和带一参初始化
    Node(const T& item,Node<T>* ptr=NULL){this->element=item;this->Next=ptr;}   //一参初始化和两参初始化
};

//栈
template<class T>
class LinkedStack{
protected:
    Node<T> *top;   //栈只需要一个表头即可
public:
    LinkedStack();
    ~LinkedStack(){MakeEmpty();}
    void MakeEmpty();       //清空栈
    void Push(const T& x);  //入栈
    Status Pop(T& x);       //退栈
    Status GetTop(T& x)const;   //取栈头 
    Status IsEmpty()const;      //判断是否是空栈
    int GetSize()const;         //取战元素个数
    void DisplayStack();
};
