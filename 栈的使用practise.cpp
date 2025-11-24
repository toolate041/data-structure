/*#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
  int i, t, k, j;
  string str;
  cin >> t;
  while (t--)
  {
    cin >> str;
    stack<char> s;
    for (i = 0; i < str.length(); i++)
    {
      s.push(str[i]);
    }
    while (!s.empty())
    {
      cout << s.top();
      s.pop();
    }
    cout << endl;
  }
}
  */
// 逆序输出字符串
/*#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
  int i, j, t, k;
  cin >> t;
  string str;
  while (t--)
  {
    stack<char> s;
    cin >> str;
    for (i = 0; i < str.length(); i++)
    {
      if (!s.empty() && str[i] == '#')
      {
        s.pop();
      }
      else if (str[i] == '#')
      {
        continue;
      }
      else
      {
        s.push(str[i]);
      }
    }
    if (s.empty())
    {
      cout << "NULL" << endl;
    }
    else
    {
      stack<char> q;
      while (!s.empty())
      {
        q.push(s.top());
        s.pop();
      }
      while (!q.empty())
      {
        cout << q.top();
        q.pop();
      }
      cout << endl;
    }
  }
}
  *///遇到#就退格操作，而后输出
/*#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
    int t;
    string str;
    cin >> t;
    while(t--) {
        cin >> str;
        stack<char> s;
        bool valid = true;
        for(int i = 0; i < str.length(); i++) {
            char c = str[i];
            if(c == '(' || c == '[' || c == '{') {
                s.push(c);
            } else if(c == ')') {
                if(s.empty() || s.top() != '(') {
                    valid = false;
                    break;
                }
                s.pop();
            } else if(c == ']') {
                if(s.empty() || s.top() != '[') {
                    valid = false;
                    break;
                }
                s.pop();
            } else if(c == '}') {
                if(s.empty() || s.top() != '{') {
                    valid = false;
                    break;
                }
                s.pop();
            }//对每个栈的操作都要考虑它是否为空
            // 非括号字符可忽略，或根据题意处理
        }
        if(valid && s.empty())
            cout << "ok" << endl;
        else
            cout << "error" << endl;
    }
    return 0;
}
    *///对于字符串匹配的正确性,是否是合法的计算式子