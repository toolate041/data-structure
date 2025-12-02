#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
  int num,i,j,k,t;
  cin>>num;
  int arr[100];
  int arr2[100];
  int final[100];
  for(i=0;i<num;i++)
  {
    cin>>arr[i];
  }
  for(i=0;i<num;i++)
  {
    cin>>arr2[i];
  }
  int cnt=num;
  for(i=0;i<num;i++)
  {
  int flag=0;
  for(j=0;j<num;j++)
  {
    if(arr2[i]==arr[j])
    {
      flag=1;
      break;
    }
  }
  if(!flag)
  {
    arr[cnt]=arr2[i];
    cnt++;
  }
  }
  
  sort(arr,arr+cnt);
  cout<<arr[(int)((cnt-1)/2)];
}