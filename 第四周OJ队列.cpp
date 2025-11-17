/*#include <iostream>
#include <queue>
#include <stack>
using namespace std;

char toChar(int d) {
	if(d<10)
	return '0'+d;
	else
	return 'A'+(d-10);                
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        double n;
        int k;
        cin >> n >> k;

        
        long long intPart = (long long)n;
        stack<int> st;
        if (intPart == 0) st.push(0);
        else while (intPart) { st.push(intPart % k); intPart /= k; }

        string intStr;
        while (!st.empty()) 
		{ 
		intStr.push_back(toChar(st.top()));
		st.pop();
	    }

        /
        double frac = n - (long long)n;
        queue<int> q;
        int cnt = 3;                // 只要 3 位
        while (cnt--) {
            frac *= k;
            int digit = (int)frac;
            if (digit >= k) digit = k - 1;   // 防浮点误差
            q.push(digit);
            frac -= digit;
        }


        cout << intStr << '.';
        while (!q.empty()) { cout << toChar(q.front()); q.pop(); }
        cout << '\n';
    }
    return 0;
}*/
/*#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int main()
{
	int i,j,t;
	cin>>t;
	char type[t];
	int time;
	queue<int> q[3];
	for(i=0;i<t;i++)
	{
		cin>>type[i];	
	}
	for(i=0;i<t;i++)
	{
		cin>>time;
		if(type[i]=='A')
		q[0].push(time);
		else if(type[i]=='B')
		q[1].push(time);
		else if(type[i]=='C')
		q[2].push(time);
	}
	for(i=0;i<3;i++)
	{
		int sum=0;
		int cnt=0;
		while(!q[i].empty())
		{
		sum+=q[i].front();
		q[i].pop();
		cnt++;	
		}
		cout<<sum/cnt<<endl;
		
		
	}
	
}*/
/*#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int main()
{
	int i,j,t;
	cin>>t;
	int num;
	queue<int> q[2];
	for(i=0;i<t;i++)
	{
		cin>>num;
		if(num%2==1)
		q[0].push(num);
		else
		q[1].push(num);
	}
	int cnt=0;
	for(i=0;i<t-1;i++)
	{
		if(cnt!=2&&!q[0].empty())
		{
		cout<<q[0].front()<<" ";
		q[0].pop();
		cnt++;	
		}
		else
		{
		cout<<q[1].front()<<" "; 
		q[1].pop();
		cnt=0;
		}
		
	}
	if(q[0].empty())
	cout<<q[1].front()<<endl;
	else
	cout<<q[0].front()<<endl;
}*///第三题 
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int main()
{
	int i,j,t,num;
	cin>>t;
	queue<int> q[t];
	int cnt=0,cnt1=0;
	int num1[1000];
	while(t--)
	{
		
		cin>>num;
		for(i=0;i<num;i++)
		{
			cin>>num;
			q[cnt].push(num);
			num1[cnt1]=num;
		}
		cnt++;
	}
}
/*#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;

    unordered_map<int, int> belong;   // 元素 -> 组号
    for (int g = 0; g < t; g++) {
        int cnt;
        cin >> cnt;
        while (cnt--) {
            int x;
            cin >> x;
            belong[x] = g;
        }
    }

    const int MAXT = 10;
    queue<int> q[MAXT];        // 每组自己的子队列
    queue<int> big;            // 有大块元素的组号队列
    bool inBig[MAXT] = {false}; // 组号是否已在 big 中

    string op;
    vector<int> out;           // 收集 DEQUEUE 输出
    while (cin >> op) {
        if (op == "STOP") break;
        if (op == "ENQUEUE") {
            int x;
            cin >> x;
            int g = belong[x];
            if (q[g].empty()) {        // 本组第一次出现
                big.push(g);
                inBig[g] = true;
            }
            q[g].push(x);
        }
        else if (op == "DEQUEUE") {
            int g = big.front();
            int x = q[g].front();
            q[g].pop();
            out.push_back(x);
            if (q[g].empty()) {
                big.pop();
                inBig[g] = false;
            }
        }
    }

    // 输出所有 DEQUEUE 结果
    for (size_t i = 0; i < out.size(); i++) {
        cout << out[i] << (i + 1 < out.size() ? ' ' : '\n');
    }
    return 0;
}*///第四题 
