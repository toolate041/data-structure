#include<iostream>
using namespace std;
int main()
{
  int i,j,k,t;
  cin>>t;
  while(t--)
  {
    cin>>k;
    int num[100];
    for(i=0;i<k;i++)
    {
      cin>>num[i];
    }
    int number=k/2;
    while(number!=0)
    {
      for(i=0;i<(k-number);i++)
      {
        if(num[i]<num[i+number])
        swap(num[i],num[i+number]);
      }
      for(i=0;i<k-1;i++)
      {
        cout<<num[i]<<" ";
      }
      cout<<num[i]<<endl;
      number/=2;
    }
    cout<<endl;
  }
}