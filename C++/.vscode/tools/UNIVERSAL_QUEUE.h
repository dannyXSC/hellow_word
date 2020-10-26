#pragma once
#include "HEADFILES.h"
/*------------------------------------------------------------------------
基本类型的通用链式队列
------------------------------------------------------------------------*/

//定义数组链表的最大存储空间
const int MaxSize=50;
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

//队列
template<class T>
class LinkedQueue{
protected:
    Node<T>* head;
    Node<T>* end;
public:
    LinkedQueue();
    ~LinkedQueue(){makeEmpty();}
    void makeEmpty();           //清空队列
    Status EnQueue(const T& x); //元素x进入队列
    Status DeQueue(T& x);     //队头元素出队列
    Status GetFront(T& x);    //读取队头元素的值
    Status IsEmpty()const;    //判断队列是否为空
    int GetSize()const;        //求队列元素个数
};