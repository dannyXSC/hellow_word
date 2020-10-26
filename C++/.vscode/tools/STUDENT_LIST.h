#pragma once
#include "HEADFILES.h"
#include "STUDENT.h"

/*------------------------------------------------------------------------
学生链表的声明
------------------------------------------------------------------------*/
/*定义新类型*/
typedef int Status;
/*宏定义*/
#define OK 1
#define ERROR 0
#define LOVERFLOW -1 
#define INFEASIBLE -2
#define TRUE 1
#define FALSE 0

//链表节点
typedef struct StudentNodeList {
    STUDENT ele;
    StudentNodeList* next; //指向头结点的指针
}NodeList, * ListPointer;

//链表声明
class StudentList {
private:
    ListPointer head;
    int num;
public:
    StudentList();  //构造函数
    ~StudentList(); //析构函数
    Status ClearList(); //清空表 不会把头结点消除
    Status ListEmpty(); //判断是不是空表 是返回true 不是返回false
    int ListLength();   //求长度
    Status GetElem(int pos, STUDENT* e); //取表中元素
    Status GetElem_by_no(int no, STUDENT* e);    //根据学号取表中元素
    int LocateElem(int no); //求no的位置，没找到返回ERROR，否则返回pos
    Status ListInsert(int pos, STUDENT e);   //在指定位置插入一个元素 可以插入的位置是[1,n+1]
    Status ListInsert_by_no(STUDENT e);     //按学号顺序插入
    //暂不用选择位置删除
    //Status ListDelete(int pos,STUDENT* e);   //删除指定位置的元素，并将被删除元素返回e中 可以删除的范围是[1,n]
    Status ListDelete(int no, STUDENT* e);   //删除指定学号的元素，并将被删除的元素返回e中
    Status Update(int no, STUDENT* e);   //更改
    Status Sort();
};