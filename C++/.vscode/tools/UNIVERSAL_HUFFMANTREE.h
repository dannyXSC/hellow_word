#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <string.h>
#include <string>   //用一点点string
#include <iomanip>  //输出格式控制头文件
#include <conio.h>  //_getche
#include <algorithm>
using namespace std;
#include "UNIVERSAL_MINHEAP.h"

/*Huffman树的建立*/

/*--------------------------------------------------------------------------------------
元素的定义
--------------------------------------------------------------------------------------*/
template<class T>
struct Element{
    T key;
    //需要定义赋值
    Element& operator=(const Element &x){this->key=x.key;}
    bool operator>(const Element &x){return this->key>x.key?true:false;}
    bool operator>=(const Element &x){return this->key>=x.key?true:false;}
    bool operator<(const Element &x){return this->key<x.key?true:false;}
    bool operator<=(const Element &x){return this->key<=x.key?true:false;}
    bool operator==(const Element &x){return this->key==x.key?true:false;}
    bool operator!=(const Element &x){return this->key!=x.key?true:false;}
};

/*--------------------------------------------------------------------------------------
树节点的定义
--------------------------------------------------------------------------------------*/
template<class T,class E>   //T是E中元素的类型  //这里E应该是Element<T>//
class HuffmanNode{          //数的节点
public:
    E data; //节点储存的数据 可以是个结构体
    HuffmanNode<T,E> *leftChild,*rightChild,*parent;    //左右子女及父亲节点
    HuffmanNode():leftChild(NULL),rightChild(NULL),parent(NULL){}   //构造函数
    HuffmanNode(E ele,HuffmanNode<T,E> *left=NULL,HuffmanNode<T,E> *right=NULL
    ,HuffmanNode<T,E> *par=NULL):data(ele),leftChild(left),rightChild(right),
    parent(par){}   //构造函数2
    HuffmanNode& operator=(const HuffmanNode &x){this->data.key=x.data.key;
    this->leftChild=x.leftChild;this->rightChild=x.rightChild;this->parent=x.parent;}
    bool operator>(const HuffmanNode &x){return this->data.key>x.data.key?true:false;}
    bool operator>=(const HuffmanNode &x){return this->data.key>=x.data.key?true:false;}
    bool operator<(const HuffmanNode &x){return this->data.key<x.data.key?true:false;}
    bool operator<=(const HuffmanNode &x){return this->data.key<=x.data.key?true:false;}
    bool operator==(const HuffmanNode &x){return this->data.key==x.data.key?true:false;}
    bool operator!=(const HuffmanNode &x){return this->data.key!=x.data.key?true:false;}
};

/*--------------------------------------------------------------------------------------
haffman树的定义
--------------------------------------------------------------------------------------*/
template<class T,class E>
class HuffmanTree{
protected:
    HuffmanNode<T,E> *root; //根节点
    void deleteTree(HuffmanNode<T,E> *t);   //删除以t为根的子树
    void mergeTree(HuffmanNode<T,E> &htl,HuffmanNode<T,E> &ht2,HuffmanNode<T,E>* &parent);  //合并二叉树 
public:
    HuffmanTree(E arr[],int n); //给一个E类型的数组和一个长度
    ~HuffmanTree(){deleteTree(root);}
};













