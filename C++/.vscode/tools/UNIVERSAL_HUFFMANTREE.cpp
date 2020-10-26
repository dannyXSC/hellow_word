#include "UNIVERSAL_HUFFMANTREE.h"

/*--------------------------------------------------------------------------------------
树节点的实现
emmm模板实在有点恶心
--------------------------------------------------------------------------------------*/
template<class T,class E>
void HuffmanTree<T,E>::deleteTree(HuffmanNode<T,E> *t)
{
    if(t==NULL)return;  //到了空节点 退出
    HuffmanNode<T,E> *p=t,*ql=t->leftChild,*qr=t->rightChild;
    delete p;   //统统元素节点
    this->deleteTree(ql);
    this->deleteTree(qr);
}
template<class T,class E>
void HuffmanTree<T,E>::mergeTree(HuffmanNode<T,E> &ht1,HuffmanNode<T,E> &ht2,HuffmanNode<T,E>* &parent)
{
    parent=new E;
    parent->parent=NULL;
    parent->leftChild=&ht1;parent->rightChild=&ht2;
    parent->data.key=ht1.data.key+ht2.data.key;
}
template<class T,class E>
HuffmanTree<T,E>::HuffmanTree(E arr[],int n)
{
    //给出n个权值arr[0]-arr[n-1] 构造Huffman树
    MinHeap<E,HuffmanNode<T,E>> hp;
    HuffmanNode<T,E> first,second,*parent;
    HuffmanNode<T,E> *NodeList;
    NodeList=new (HuffmanNode<T,E>[n]());
    if(NodeList==NULL)exit(-1);

    for(int i=0;i<n;i++)
    {
        NodeList[i].data=arr[i];
        NodeList[i].leftChild=NULL;
    }
}

int  main()
{
    ;
}





