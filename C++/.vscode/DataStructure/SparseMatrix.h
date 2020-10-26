#pragma once
#include "../tools/HEADFILES.h"
/*----------------------------------------------------------
用链表方式存储稀疏矩阵
表头结点的头结点 HeadMaster r,c,exist_num,*head
规定行列都从第一行第一列开始数
----------------------------------------------------------*/

/*定义新类型*/
typedef int Status;
/*宏定义*/
#define OK 1
#define ERROR 0
#define LOVERFLOW -1 
#define INFEASIBLE -2
#define TRUE 1
#define FALSE 0

//基本元素
class Element{
private:
    friend class HeadMaster;
    int r;
    int c;
    int value;
public:
    Element();  //构造函数
    Element(int r,int c,int value);
    friend istream& operator>>(istream& in,Element& ele);   //重载输入
    Element& operator=(const Element& ele);                 //复制的重载

};

//结点
typedef class Node{
private:
    //定义友元
    friend class HeadMaster;

    bool is_head;

    //头结点
    Node* next_head;
    Node* col_next; //同一列的下一个
    Node* row_next; //同一行的下一个

    //普通结点
    //共用上面的col_next和row_next
    Element ele;    //储存元素
public:
    //节点中的成员函数主要要实现的是构造函数
    Node();         //普通结点的默认构造
    Node(Element ele);  //普通节点有参数构造
    Node(int t);    //头结点的构造
}*NodePointer;

//表头结点的头结点
typedef class HeadMaster{
private:
    //私有成员
    int r;
    int c;
    int exist_num;
    NodePointer head;   //指向第一个头结点
    //私有函数
    NodePointer find_head(int x);   //找到值为x的头结点的地址
    Status Insert_in_r(NodePointer cur_head,const Element& ele);    //在cur_head的行中顺序插入一个节点
    Status Insert_in_c(NodePointer cur_head,const Element& ele);    //列
public:
    HeadMaster(int r,int c);
    ~HeadMaster();
    Status Insert(Element ele);             //给一个element值插入
    Status Insert(int r,int c,int value);   //给具体值插入
    void ShowMatrix();
}SparseMatrix;