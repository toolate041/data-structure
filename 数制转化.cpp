#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        double num;
        int set;
        cin >> num >> set;//num是被转换的数字，set是数制
        int m = (int)num;
        double n = num - m;
        stack<int> s;
        queue<int> q;

        while (m)
         { 
          s.push(m % set);
           m /= set;
         }//处理整数部分，栈
        if (s.empty()) 
        {
          s.push(0);
        }//整数部分为0时，直接压入0
        for (int i = 0; i < 3; ++i) {
            n *= set;
            int digit = int(n);
            q.push(digit);
            n -= digit;
        }//循环处理小数部分，取相乘后的整数部分，再用小数部分乘

        while (!s.empty()) {
            int d = s.top(); 
            s.pop();
            cout << char(d < 10 ? d + '0' : d - 10 + 'A');
        }//整数的输出

        cout << '.';
        for (int i = 0; i < 3; ++i) {
            int d = q.front(); 
            q.pop();
            cout << char(d < 10 ? d + '0' : d - 10 + 'A');
        }
        cout << '\n';
    }
    return 0;
}