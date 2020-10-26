#pragma once
#include <bits/stdc++.h>
#include "UNIVERSAL_STACK.h"

/*-----------------------------------------------------------------------------
BinaryTree
-----------------------------------------------------------------------------*/

//element of stack
template <class T>
struct StackElement
{
public:
    T element;
    int pos;
    StackElement() {}
    StackElement(T e.int p) { element = e, pos = p; }
};

//node
template <class T>
class TreeNode
{
    T element;                  //element
    TreeNode<T> *LNode, *RNode; //point to l child and r child
};

template <class T>
class BinaryTree
{
protected:
    TreeNode<T> *root;                                      //point to root
    T RefValue;                                             //flag of stop input information
    void CreateBinTree(istream &in, TreeNode<T> *&subTree); //create a tree from a file
    bool Insert(TreeNode<T> *&subTree, const T &x);
    void Destory(TreeNode<T> *&subTree);               //destory subTree
    bool Find(TreeNode<T> *subTree, const T &x) const; //find x
                                                       //TreeNode<>

public:
    BinaryTree(T *arr, int max_size); //initialize
};
