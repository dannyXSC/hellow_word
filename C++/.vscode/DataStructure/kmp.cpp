
/*
kmp算法
寻找匹配子串
*/

#include <iostream>
#include <cstring>
using namespace std;

/*字符串的最大长度*/
const int max_length=1024;

/*-------------------------------------------------
next数组的维护
-------------------------------------------------*/
int NEXT[max_length];  //储存对应前缀的结尾位置 从1开始使用 next[0]储存长度

void solve_next(char* match)    //对匹配串进行的操作
{
    int i,j;    //i对应后缀的位置，j对应前缀的位置
    /*初始条件*/
    NEXT[0]=strlen(match);  //next0储存长度
    NEXT[1]=0;      //为什么是0
    i=1;j=0;        //i指向第一个元素
    while(i<NEXT[0])
    {
        if(j==0||match[i]==match[j])
        {
            i++;j++;
            NEXT[i]=j;
            //printf("(%d,%d)%d\n",i,j,NEXT[i]);
        }
        else
        {
            j=NEXT[j];  //去找前驱
        }
        
    }
}

/*-------------------------------------------------
实现查找    
返回值>=0即找到
=-1即未找到
-------------------------------------------------*/
int solve(char* target,char* match)
{
    int i=0;  //指向target的指针（不回溯）
    int j=0;  //指向match的指针
    int len=strlen(target);
    memset(NEXT,0,sizeof(NEXT));    //初始化NEXT数组
    solve_next(match);  //给NEXT数组赋值
    while(i+NEXT[0]<=len)
    {
        //cout<<"*";
        while(target[i]==match[j])
        {
            i++;
            j++;
            if(j>=NEXT[0])      //发现匹配的串了
            {
                return i-NEXT[0];
            }
        }
        //到这里即不完全匹配 此时的target[i]！=match[j]
        if(j==0)    //如果头都不匹配
        {
            i++;j++;
            continue;
        }
        //部分匹配的情况
        j=NEXT[j+1]-1;  //把match串向后移到前缀的尾端
    }
    return -1;
}



int main()
{
    char a[max_length],b[max_length];
    while(1)
    {
        cin>>a>>b;
        cout<<solve(a,b)<<endl;
    }
    return 0;
}
