#include<iostream>
using namespace std;
int findposition(int arr[], int num, int st, int end)
{
    while (st < end) {                    // 区间 [st, end) 半开
        int mid = st + (end - st) / 2;    // 防溢出
        if (arr[mid] == num)  return mid + 1; // 位置从 1 开始
        else if (arr[mid] < num) st = mid + 1;
        else                     end = mid;
    }
    return 0;                             // 没找到
    //用循环解决，不用递归
}
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
  cin>>k;
  while(k--)
  {
    cin>>num;
    int pos=findposition(arr,num,0,t);
    if(!pos)
    cout<<"error"<<endl;
    else
    cout<<pos<<endl;
  }
}