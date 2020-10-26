
/*
回溯法
注：如果在回溯法中用了辅助的全局变量，一定要及时把他们恢复原状
    特别的，若函数有多个出口，则需要在每个出口处恢复被修改的值
*/

#include <iostream>
using namespace std;

/*八皇后问题*/
const int maxn=100;
int n;  //n个皇后
int ans[maxn];  //存储第i行的皇后的位置
int lu_rd[2*maxn-1];    //储存从左上到右下的信息
int ld_ru[2*maxn-1];    //储存从左下到右上的信息
int u_d[maxn];  //储存从上到下的信息

void solve(int cur)
{
    int i;
    //结束条件
    if(cur==n)
    {
        for(i=0;i<n;i++)
        {
            printf("(%d,%d)",i,ans[i]);
        }
        cout<<endl;
    }
    for(i=0;i<n;i++)    //循环纵坐标
    {
        int inf1=cur-i+n-1;
        int inf2=cur+i;
        if(!(u_d[i]||lu_rd[inf1]||ld_ru[inf2]))
        {
            u_d[i]=lu_rd[inf1]=ld_ru[inf2]=1;
            ans[cur]=i;
            solve(cur+1);
            u_d[i]=lu_rd[inf1]=ld_ru[inf2]=0;   //切记一定要改回来，否则就一个解了
        }
    }
    return;
}

int main()
{
    cin>>n;
    solve(0);
    return 0;
}