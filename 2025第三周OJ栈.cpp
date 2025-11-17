/*#include<iostream>
#include<stack>//栈的头文件 
#include<cmath>
#include<algorithm>
using namespace std;
 int main() {
    int t;
    cin>>t;   // 读取测试数据组数
    string str;
    while (t--) {
        cin >> str;              // 读入不含空格的字符串
        stack<char> s;           //创建栈的对象 
        for (char ch : str)      // 顺序压栈
            s.push(ch);
        while (!s.empty()) {     // 逆序输出
            cout << s.top();
            s.pop();
        }
        cout << endl;
    }

}*/
/*#include<iostream>
#include<stack>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	cin>>t;
	int a,b;
	while(t--)
	{
		int n=0;
		cin>>a>>b;
		stack<int> s;
		while(a)
		{
			int c=a%b;
			s.push(c);
			n++;
			a/=b;
		}
		for(int i=0;i<n;i++)
		{
			if(s.top()>9)
			cout<<(char)('A'+s.top()-10);
			else
			cout<<s.top();
			s.pop();
		}
		cout<<endl;
	}
 }
 */
/*#include<iostream>
#include<stack>
#include<cmath>
#include<algorithm>
using namespace std; 
int main()
{
	int i,j,t,a,b;
	string str;
	cin>>t;
	while(t--)
	{
		int n=0;
		stack<char> s;
		cin>>str;
		for(char ch:str)
		{
			if(ch!='#')
			s.push(ch);
			else if(ch=='#'&&s.empty())
			continue;
			else
			s.pop();
		}
		if(s.empty())
		cout<<"NULL"<<endl;
		else
		{
			stack<char> t;
			while(!s.empty())
			{
				char m=s.top();
				t.push(m);
				s.pop();
				n++;
			}
			for(i=0;i<n;i++)
			{
				cout<<t.top();
				t.pop();
			}
			cout<<endl;
		}
	}
}*/
/*#include<iostream>
#include<stack>
#include<cmath>
#include<algorithm>
using namespace std; 
int main()
{
	int i,j,t;
	cin>>t;
	string str;
	while(t--)
	{
		stack<char> s;
		cin>>str;
		for(char ch:str)
		{
			if(ch=='('||ch=='['||ch=='{')
			s.push(ch);
			else if(ch==')')
			{
			if(s.top()&&s.top()=='(')
			s.pop();
			else
			{
				cout<<"error"<<endl;
				break;
			}
			}
			else if(ch==']')
			{
			if(s.top()&&s.top()=='[')
			s.pop();
			else
			{
				cout<<"error"<<endl;
				break;
			}
			}
			else if(ch=='}')
			{
			if(s.top()&&s.top()=='{')
			s.pop();
			else
			{
				cout<<"error"<<endl;
				break;
			}
			}
			else
			continue;
				
		}
		if(s.empty())
		cout<<"ok"<<endl;
		else
		cout<<"error"<<endl;
	}
}*/
/*#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string cur = "https://www-acm-org.webvpn.szu.edu.cn/"; // 初始页
    stack<string> back, forward;
    string cmd, url;

    while (cin >> cmd) {
        if (cmd == "VISIT") {//每一次的VISIT都会把向前栈给覆盖 
            cin >> url;
            back.push(cur);   // 旧页面进后退栈
            cur = url;        // 更新当前页
            while (!forward.empty()) forward.pop(); // 清空前向栈
            cout << cur << '\n';
        }
        else if (cmd == "BACK") {
            if (back.empty()) {
                cout << "Ignored\n";
            } else {
                forward.push(cur); // 当前页先进前向栈
                cur = back.top();  // 后退一页
                back.pop();
                cout << cur << '\n';
            }
        }
        else if (cmd == "FORWARD") {
            if (forward.empty()) {
                cout << "Ignored\n";
            } else {
                back.push(cur);       // 当前页进后退栈
                cur = forward.top();  // 前进一页
                forward.pop();
                cout << cur << '\n';
            }
        }
        else if (cmd == "QUIT") {
            break;
        }
    }
    return 0;
}*/
#include <iostream>
#include <iomanip>
#include <stack>
#include <cctype>
#include <string>
using namespace std;

/* 计算中缀表达式（浮点版），表达式末尾带 '#' */
double eval(const string &s) {
    stack<double> num;
    stack<char>   op;
    auto priority = [](char c)->int {
        if (c == '+' || c == '-') return 1;
        if (c == '*' || c == '/') return 2;
        return 0;                  // '('
    };
    auto calc = [&]() {
        double b = num.top(); num.pop();
        double a = num.top(); num.pop();
        char c = op.top(); op.pop();
        switch (c) {
            case '+': num.push(a + b); break;
            case '-': num.push(a - b); break;
            case '*': num.push(a * b); break;
            case '/': num.push(a / b); break;
        }
    };

    for (size_t i = 0; i < s.size(); ++i) {
        char c = s[i];
        if (c == '#') break;
        if (isspace(c)) continue;
        if (c == '(') { op.push(c); continue; }

        if (c == ')') {                       // 计算到 '('
            while (op.top() != '(') calc();
            op.pop();                         // 弹 '('
            continue;
        }
        if (isdigit(c) || c == '.') {         // 读取数字（可能带小数点）
            double v = 0, base = 1;
            bool frac = false;
            while (i < s.size() &&
                   (isdigit(s[i]) || s[i] == '.')) {
                if (s[i] == '.') { frac = true; ++i; continue; }
                if (!frac) v = v * 10 + (s[i] - '0');
                else { base /= 10; v += (s[i] - '0') * base; }
                ++i;
            }
            num.push(v);
            --i;                              // for 会再 ++
            continue;
        }
        /* 运算符 */
        while (!op.empty() && priority(op.top()) >= priority(c))
            calc();
        op.push(c);
    }
    while (!op.empty()) calc();
    return num.top();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    cin.ignore();                         // 吃掉行尾
    cout << fixed << setprecision(4);
    while (t--) {
        string line;
        getline(cin, line);               // 整行读入
        cout << eval(line) << '\n';
    }
    return 0;
}
