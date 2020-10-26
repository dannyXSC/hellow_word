/*1951565 软02 xsc*/
#include <iostream>
#include <string.h>
using namespace std;

const int width=3;
const int high=5;

//最长数
const int max_length=9;
//存每一位数据的数组
int num_bit[max_length];

const char num[][high][width]={
	//数字 高度 宽度
	{1,1,1,
	 1,0,1,
	 1,0,1,
	 1,0,1,
	 1,1,1
	},
	{0,0,1,
	 0,0,1,
	 0,0,1,
	 0,0,1,
	 0,0,1
	},
	{1,1,1,
	 0,0,1,
	 1,1,1,
	 1,0,0,
	 1,1,1
	},
	{1,1,1,
	 0,0,1,
	 1,1,1,
	 0,0,1,
	 1,1,1
	},
	{1,0,1,
	 1,0,1,
	 1,1,1,
	 0,0,1,
	 0,0,1
	},
	{1,1,1,
	 1,0,0,
	 1,1,1,
	 0,0,1,
	 1,1,1
	},
	{1,1,1,
	 1,0,0,
	 1,1,1,
	 1,0,1,
	 1,1,1
	},
	{1,1,1,
	 0,0,1,
	 0,0,1,
	 0,0,1,
	 0,0,1
	},
	{1,1,1,
	 1,0,1,
	 1,1,1,
	 1,0,1,
	 1,1,1
	},
	{1,1,1,
	 1,0,1,
	 1,1,1,
	 0,0,1,
	 1,1,1
	}
};

void _print(int x)
{
	int i,j;
	for(i=0;i<high;i++)
	{
		for(j=0;j<width;j++)
		{
			if(num[x][i][j])
			{
				cout<<"* ";
			}
			else
			{
				cout<<"  ";
			}
		}
		cout<<endl;
	}
	return;
}

int _print_nums(int x)
{
	//小于0退出
	if(x<0)return -1;
	int i,j,k;
	int length=1;
	int tempx=x;
	while(tempx/10)
	{
		length++;
		tempx=tempx/10;
	}
	if(length>max_length)
	{
		cout<<"ERROR:输入数据长度过长"<<endl;
		return -1;
	}
	for(i=0,tempx=x;i<length;i++)
	{
		num_bit[i]=tempx%10;
		tempx=tempx/10;
	}

	for(i=0;i<high;i++)
	{
		for(j=length-1;j>=0;j--)	//打印几个数字
		{
			for(k=0;k<width;k++)	//打印具体的数字
			{
				if(num[num_bit[j]][i][k])
				{
					cout<<"* ";
				}
				else
				{
					cout<<"  ";
				}
			}
			cout<<"  ";
		}
		cout<<endl;
	}
	return 0;
}


//封装成类
//class PRINT_NUM{
///private:
//	int num_bit[max_length];	//用来保存每一位数据的数组
//public:
//
//}


int main()
{
	int n;
	while(1)
	{
		memset(num_bit,0,sizeof(num_bit));
		cin>>n;
		_print_nums(n);
	}
}
