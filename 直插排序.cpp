#include<iostream>
using namespace std;
void insertqueue(int num[100],int t)
{
    int i,j,m;
    for(i=1;i<t;i++)//7个数字只用排序6次
    {
      int temp=num[i];
      for(j=i;j>0;j--)
      {
        if(temp<num[j-1])//要跟自己前一个比，所以是j-1
        {
          num[j]=num[j-1];//小于的话就向后移动
        }
        else
        {
          break;//大于了就退出
        }
      }   
      num[j]=temp;//在这个地方插入数字
      for(m=0;m<t-1;m++)
      {
        cout<<num[m]<<" ";
      }
      cout<<num[m]<<endl;
    }
}
int main()
{
  int i,j,k,t,m;
  cin>>t;
  int num[100];
  for(i=0;i<t;i++)
  {
    cin>>num[i];
  }
  insertqueue(num,t);
  
}