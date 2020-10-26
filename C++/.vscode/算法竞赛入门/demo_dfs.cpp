#include <iostream>
#include <string.h>
using namespace std;

#define barrier '*'
#define target '@'

const int maxn=1000,maxm=1000;  //分别为最大行数和列数
int n,m;    //n,m为输入的行列数
char ele[maxn][maxm];   //表格中的元素
int val[maxn][maxm];

int dfs(int r,int c,int id)
{
    //判断是否出界
    if(r<0||r>=n||c<0||c>=m)return 0;
    //结束条件 本元素不是目标元素或者已经算过
    if(barrier==ele[r][c]||val[r][c]>0)return 0;
    //对需要dfs的元素进行操作
    //进行id赋值
    val[r][c]=id;
    //对四周进行dfs
    int i,j;
    for(i=-1;i<=1;i++)
    {
        for(j=-1;j<=1;j++)
        {
            if(0==i*j&&!(i==0&&j==0))
            {
                dfs(r+i,c+j,id);
            }
        }
    }
    //此时已经对四周都进行了dfs，遍历完成
    return 1;
}
//下面是测试程序
/*
3 3
@ @ *
@ * @
* @ *
*/
int main()
{
    int i,j;
    int id=1;
    cin>>n>>m;
    //初始化数组
    memset(ele,0,sizeof(ele));
    memset(val,0,sizeof(val));
    //读入元素
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>ele[i][j];
        }
    }
    //进行dfs
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(dfs(i,j,id))
            {
                id++;
            }
        }
    }
    //输出
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<val[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}