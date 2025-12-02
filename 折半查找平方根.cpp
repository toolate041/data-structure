#include <iostream>
#include <iomanip>
using namespace std;
double findpos(double stand, double start, double end)
{
  int cnt = 0;
  while (true)
  {
    double x = (start + end)/2;
    double k = x * x - stand;
    if (k < 0)
      k = -k;
    if (k < 0.00001)
    {
      cnt++;
      cout<<cnt<<" ";
      return x;
    }
    else if (x * x < stand)
    {
      start = x;
    }
    else
    {
      end = x;
    }
    cnt++;
    
  }
  
}
int main()
{
  double i, j, t, k;
  cin >> t;
  while (t--)
  {
    cin >> k;
    double m = findpos(k, 0, k);
    cout << fixed << setprecision(3) << m<<endl;
  }
}