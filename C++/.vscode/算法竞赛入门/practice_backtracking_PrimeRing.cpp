
/*
素数环
*/

#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

const int maxn=20;
int n;
int ans[maxn];  //输出结果（在i位置填什么数）
int mark[maxn]; //记录每个数是否被使用过 使用过1 无0
int is_p[maxn*2]; //记录i是不是素数

int is_prime(int target)
{
    for(int i=2;i<=target/2;i++)
    {
        if(target%i==0)
        {
            return 0;
        }
    }
    return 1;
}

void solve(int cur)
{
    int i;
    //结束条件
    if(cur==n)
    {
        
        if(is_p[ans[cur-1]+1])
        {
            for(i=0;i<n;i++)
            {
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    //执行操作
    for(i=1;i<=n;i++)
    {
        if(!mark[i]&&is_p[ans[cur-1]+i])
        {
            mark[i]=1;
            ans[cur]=i;
            solve(cur+1);
            mark[i]=0;  //改回来
        }
    }
    return;
}


int main()
{
    cin>>n;
    memset(mark,0,sizeof(mark));
    is_prime(n*2);
    ans[0]=1;   //第一个一定是1
    mark[1]=1;
    //生成素数表
    for(int i=1;i<=n*3;i++)
    {
        is_p[i]=is_prime(i);
    }
    solve(1);
}