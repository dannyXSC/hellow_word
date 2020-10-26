/*
排列组合
大一没解决的题目这里 解决了 ！！！
1、递归
2、用STL next_permutation
*/

#include <iostream>
#include <algorithm>
using namespace std;

const int maxn=9;   //排列数最大
int n;     //n个数的排列 

int ans[maxn];

void _print()
{
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return;
}

void print_permutaion(int cur)
{
    if(cur==n)
    {
        _print();
        return;
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            int flag=1;
            for(int j=0;j<cur;j++)
            {
                if(ans[j]==i)
                {
                    flag=0;
                    break;
                }
            }
            if(flag==0)continue;
            ans[cur]=i;
            print_permutaion(cur+1);
        }
    }
    return;
}

int main()
{
    cin>>n;
    /*使用递归*/
    //print_permutaion(0);
    /*使用库函数*/
    for(int i=0;i<n;i++)ans[i]=i+1;
    do{
        _print();
    }while(next_permutation(ans,ans+n));
    return 0;
}