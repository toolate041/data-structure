#include<iostream>
using namespace std;
int main()
{
  int i,j,t,k;
  int target,num;
  cin>>t;
  int arr[1000];
  for(i=0;i<t;i++)
  {
    cin>>arr[i];
  }
  target=arr[t-1];
  cin>>k;
  while(k--)
  {
    cin>>num;
    int flag=0;
    int tip=0;
    if(num==target)
    {
      cout<<t;
    }
    else{
      while(arr[flag]!=target)
    {
      if(arr[flag]==num)
      {
        cout<<flag+1<<endl;
        tip=1;
        break;
      }
      else{
        flag++;
      }
    }
    if(!tip)
    cout<<"error"<<endl;
    }
    
  }
}