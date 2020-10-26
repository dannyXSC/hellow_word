/*------------------------------------------------------------------------
队列的抽象数据类型的实现
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

//虚基类的声明
template<class T>
class MyQueue{
public:
    MyQueue(){};                        //构造
    ~MyQueue(){};                       //析构
    virtual Status EnQueue(const T& x)=0; //元素x进入队列
    virtual Status DeQueue(T& x)=0;     //队头元素出队列
    virtual Status GetFront(T& x)=0;    //读取队头元素的值
    virtual Status IsEmpty()const=0;    //判断队列是否为空
    virtual Status IsFull()const=0;     //判断队列是否满了
    virtual int GetSize()const=0;        //求队列元素个数
};