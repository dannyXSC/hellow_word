/*
本例思考递归函数的时间复杂度
*/

/*
考虑求x的n次方的函数
*/

#include <iostream>
#include <string.h>
using namespace std;

//时间复杂度为O（n）
int fun1_0(int x,int n)
{
    int sum=1;
    for(int i=0;i<n;i++)
    {
        sum=sum*x;
    }
    return sum;
}

//上面这种做法明显过于呆板（为什么一定要一个一个乘呢）
//但是复杂度还是O（n）
int fun1_1(int x,int n)
{
    int x1=x*x;
    int sum;
    for(int i=0;i<n/2;i++)
    {
        sum=sum*x1;
    }
    if(n%2)
    {
        sum=sum*x;
    }
    return sum;
}

//考虑递归
//但是递归还是o（n）
int fun2_0(int x,int n)
{
    //结束条件
    if(n==0)return 1;
    //执行操作
    return fun2_0(x,n-1)*x;
}

//递归如何类似循环减少复杂度?
//差不多达到了o(logn)级别
const int maxn=1000;
int ans_pow[maxn];  //用来记录底层次方
int fun2_1(int x,int n)
{
    //结束条件
    if(n==0)return 1;
    //执行操作
    if(ans_pow[n/2]==0)
    {
        ans_pow[n/2]=fun2_1(x,n/2);
    }
    if(n%2)
    {
        return ans_pow[n/2]*ans_pow[n/2]*x;
    }
    else
    {
        return ans_pow[n/2]*ans_pow[n/2];
    }
}

//但是实际上上面的函数并不需要记忆，因为只用一次
//所以改进
int fun2_2(int x,int n)
{
    //结束条件
    if(n==0)return 1;
    //执行操作
    int temp=fun2_1(x,n/2);
    if(n%2)
    {
        return temp*temp*x;
    }
    else
    {
        return temp*temp;
    }
}

int main()
{
    memset(ans_pow,0,sizeof(ans_pow));  //初始化数组
    int x,n;
    cin>>x>>n;
    cout<<fun2_2(x,n);
    return 0;
}