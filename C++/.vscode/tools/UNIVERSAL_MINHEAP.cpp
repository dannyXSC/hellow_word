#include "UNIVERSAL_MINHEAP.h"

/*实现*/
template<class T>
MinHeap<T>::MinHeap(int V)
{
    heap=new T[V];
    if(heap==NULL)exit(-1);
    this->maxsize=V;
    this->volumn=0;
}
template<class T>
MinHeap<T>::MinHeap(T arr[],int n)
{
    this->maxsize=maxn<n?n:maxn;
    this->volumn=n;
    this->heap=new T[maxsize];
    if(this->heap==NULL)exit(-1);    //退出
    for(int i=0;i<n;i++)heap[i]=arr[i]; //赋值
    //进行排序
    int curpos=(n-2)/2; //找到第一个最下面的父亲节点
    while(curpos>=0)
    {
        siftDown(curpos,n-1);   //下落
        curpos--;       //向前一个节点
    }
    
}
template<class T>
MinHeap<T>::~MinHeap()
{
    //析构
    delete []this->heap;
}
template<class T>
void MinHeap<T>::siftDown(int start,int end)
{
    int i=start,j=2*i+1;
    T temp=heap[i];
    while(j<=end)
    {
        if(j<end&&heap[j]>heap[j+1])j++;
        if(temp<=heap[j])break; //结束
        else
        {
            //交换
            heap[i]=heap[j];
            i=j;
            j=i*2+1;
        }
    }
    heap[i]=temp;   //放回
}
template<class T>
void MinHeap<T>::filterUp(int start)
{
    //从current开始到0结束
    //从末尾插入，直到父亲节点小于它或者到根节点
    int j=start,i=(j-1)/2;
    T temp=heap[j];
    while(j>0)
    {
        if(heap[i]<=temp)break;
        else
        {
            heap[j]=heap[i];
            j=i;
            i=(j-1)/2;
        }
    }
    heap[j]=temp;
}
template<class T>
Status MinHeap<T>::push(const T &x)
{
    if(this->volumn==maxsize)return LOVERFLOW;
    heap[volumn]=x;
    this->filterUp(volumn);
    volumn++;
    return OK;
}
template<class T>
Status MinHeap<T>::pop(T &x)
{
    if(volumn==0)return ERROR;
    x=heap[0];heap[0]=heap[volumn-1];
    volumn--;
    siftDown(0,volumn-1);
    return OK;
}
template<class T>
Status MinHeap<T>::top(T &x)
{
    if(volumn==0)return ERROR;
    x=heap[0];
    return OK;
}
template<class T>
Status MinHeap<T>::is_empty()
{
    if(this->volumn==0)return YES;
    else return NO;
}

