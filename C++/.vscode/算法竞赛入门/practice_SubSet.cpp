
/*
子集的生成
*/

/*
递归函数的时间复杂度
递归次数*递归执行的操作次数
*/

#include <iostream>
#include <algorithm>
using namespace std;


const int maxn=1000;
int n;  //输入的几何数
int ans[maxn];  //输出的数组

//增量构造法构造递归函数
void print_subset1(int cur)
{
    int i;
    //输出集合
    for(i=0;i<cur;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    //结束条件
    if(n==cur)return;
    //执行操作
    int temp=cur?ans[cur-1]+1:0;
    for(i=temp;i<n;i++)
    {
        ans[cur]=i;
        print_subset1(cur+1);
    }
    return;
}

/*位向量法构造*/
void print_subset2(int cur)
{
    int i;
    //结束条件
    if(cur==n)
    {
        int cnt=0;
        for(i=0;i<n;i++)
        {
            if(ans[i])
            {
                cnt++;
                cout<<i+1<<" ";
            }
        }
        if(!cnt)
        {
            cout<<"0 ";
        }
        cout<<endl;
        return;
    }
    //执行操作
    for(i=0;i<2;i++)    //赋0\1表示输出或者不输出
    {
        ans[cur]=i;
        print_subset2(cur+1);
    }
    return;
}

int main()
{
    cin>>n;
    print_subset1(0);
    return 0;
}