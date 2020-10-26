/*本练习为P165 abbott的复仇*/
#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;

/*定义标准转向和方向*/
const char* re_dir="NESW";
const char* re_turn="FLR";

int dir_to_n(char c)
{
    return strchr(re_dir,c)-re_dir;
}
int turn_to_n(char c)
{
    return strchr(re_turn,c)-re_turn;
}

/*定义每个节点的状态变量Node*/
typedef struct Node{
    int r;
    int c;
    int dir;    //分别用0-3表示NESW
    Node(){};
    Node(int r,int c,int dir)
    {
        this->r=r;
        this->c=c;
        this->dir=dir;
    }
}Node;

int n,m;    //记录输入的行列
const int maxn=10,maxm=10,maxdir=4; //最大行数、列数、方向数
int steps[maxn][maxm][maxdir];  //记录最小步数，有步数即被访问过
Node pre[maxn][maxm][maxdir];   //为了输出，记录子节点的父亲节点
int sta[maxn][maxm][maxdir][maxdir];   //记录每个节点以dir1方式走来是否可以以dir2方式离开,可以为1不行为0

//储存移动对r、c的影响
const int move_r[]={-1,0,1,0};
const int move_c[]={0,1,0,-1};

//最大数组
const int max_arr=1024;

//u位置向dir走turn之后的Node状态
Node walk(const Node&u,int turn)
{
    int dir=u.dir;
    if(1==turn)
    {
        //逆时针
        dir=(dir+3)%4;
    }
    if(2==turn)
    {
        //顺时针
        dir=(dir+1)%4;
    }
    Node temp{u.r+move_r[dir],u.c+move_c[dir],dir};
    return temp;
}

//解决
void solve(int r_in,int c_in,int dir_in,int r_out,int c_out,int dir_out)
{
    queue<Node> q;
    memset(steps,-1,sizeof(steps));
    //计算初值
    Node u{r_in,c_in,dir_in};       //起点的node
    steps[r_in][c_in][dir_in]=0;    //起点步数初始化
    pre[u.r+move_r[dir_in]][u.c+move_c[dir_in]][u.dir]=u;
    u=Node(u.r+move_r[dir_in],u.c+move_c[dir_in],u.dir);
    steps[u.r][u.c][u.dir]=1;       //第一个点初始化
    q.push(u);
    while(!q.empty())
    {
        //从队列中取出第一个（可以保持步调一致
        Node u=q.front();q.pop();
        //结束条件
        if(u.r==r_out&&u.c==c_out)
        {
            print_ans(u,r_in,c_in,dir_in);
            return;
        }
        //对三种行走方式进行穷举
        for(int i=0;i<3;i++)
        {
            Node v=walk(u,i);
            //可以走的条件是：这个节点可以这样走、没以同样方式来过、不越界
            if(sta[u.r][u.c][u.dir][i]&&steps[u.r][u.c][u.dir]<0
            &&v.r>=0&&v.r<n&&v.c>=0&&v.c<m)
            {
                //维护步数数组
                steps[v.r][v.c][v.dir]=steps[u.r][u.c][u.dir]+1;
                //维护父亲数组
                pre[v.r][v.c][v.dir]=u;
                //把
                q.push(v);
            }
        }
    }
    printf("no solution\n");
}

void print_ans(Node u,int r_in,int c_in,int dir_in)
{
    vector<Node> q; //用来记录走过的每个节点（倒序
    //把节点记录
    while(1)
    {
        q.push_back(u);
        if(steps[u.r][u.c][u.dir]==0)break;
        u=pre[u.r][u.c][u.dir];
    }
    //输出vector的内容
    int cnt=0;
    for(int i=q.size()-1;i>=0;i--)
    {
        printf("(%d,%d)",q[i].r,q[i].c);
        if(++cnt%10==0)cout<<endl;
    }
}

int main()
{
    int r_in,c_in,dir_in,r_out,c_out,dir_out;
    cin>>n>>n;
    cin>>r_in>>c_in>>dir_in>>r_out>>c_out>>dir_out;

    char a[max_arr];
    while(cin.getline(a,'*'))
    {
        ;
    } 
}