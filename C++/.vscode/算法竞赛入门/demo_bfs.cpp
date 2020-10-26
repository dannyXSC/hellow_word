#include <iostream>
#include <string.h>
using namespace std;

#define barrier 0
#define Status int

const int INF_mem=0x7F;
const int INF=0x3f3f3f3f;
const int maxn=1000,maxm=1000;  //分别为最大行数和列数
int n,m;    //n,m为输入的行列数

int steps[maxn][maxm];  //最短步数（初始为inf）
int ele[maxn][maxm];    //元素类型

Status bfs(int r,int c)
{
    //结束条件(出界\barrier)
    if(r<0||r>=n||c<0||c>=m)return 0;
    if(barrier==ele[r][c])return 0;
    //开始bfs
    if(r==0&&c)
    {
        if(steps[r][c-1]+1<steps[r][c])
        {
            steps[r][c]=steps[r][c-1]+1;
        }
    }
    else if(c==0&&r)
    {
        if(steps[r-1][c]+1<steps[r][c])
        {
            steps[r][c]=steps[r-1][c]+1;
        }
    }
    else if(!c&&!r)
    {
        steps[r][c]=0;
    }
    else
    {
        if(steps[r][c-1]+1<steps[r][c])
        {
            steps[r][c]=steps[r][c-1]+1;
        }
        else if(steps[r-1][c]+1<steps[r][c])
        {
            steps[r][c]=steps[r-1][c]+1;
        }
    }
    bfs(r+1,c);
    bfs(r,c+1);
    return 1;
}