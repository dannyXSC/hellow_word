/*重点 sort lower_bound  upper_bound  binary_search*/


#include <iostream>
#include <algorithm>
using namespace std;
const  int maxn=10000;
int main()
{
    int N,Q,kase=0,a[maxn],x,i,j;
    while(2==scanf("%d%d",&N,&Q)&&N)
    {
        cout<<"CASE# "<<++kase<<":"<<endl;
        for(i=0;i<N;i++)
        {
            cin>>a[i];
        }
        sort(a,a+N);
        while(Q--)
        {
            cin>>x;
            int p=lower_bound(a,a+N,x)-a;
            if(a[p]==x)
            {
                cout<<x<<" found at "<<p<<endl;
            }
            else
            {
                cout<<x<<" not found"<<endl;
            }
            
        }
    }
}