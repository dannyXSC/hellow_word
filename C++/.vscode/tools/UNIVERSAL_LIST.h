#pragma once
#include "HEADFILES.h"

/*------------------------------------------------------------------------
基本类型的通用链表
------------------------------------------------------------------------*/
/*定义状态变量（int的别名）*/
typedef int Status;
/*宏定义*/
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

template<class T>
class LinkList{
    
};