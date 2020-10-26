#pragma once
#include "HEADFILES.h"

//堆的最大容积
const int maxn=10005;
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

/*小根堆*/
template<class T>
class MinHeap{
protected:
    T *heap;
    int volumn;
    int maxsize;
    void filterUp(int start);
    void siftDown(int start,int end);
public:
    MinHeap(int V=maxn);
    MinHeap(T arr[],int n);
    ~MinHeap();
    Status push(const T &x);    //插入一个
    Status pop(T &x);           //堆顶出堆
    Status top(T &x);           //取堆顶
    Status is_empty();
};
