/*#include <iostream>
#include <cstring>
using namespace std;

const int N = 10005;          // 主串最大长度
char S[N], P[N];              // S 主串，P 模式串
int nxt[N];                   // next 数组

//计算 next[0..m-1]，课本 4.2 节经典写法
void getNext(int m) {
    int i = 0, j = -1;
    nxt[0] = -1;              // 初始化
    while (i < m) {
        if (j == -1 || P[i] == P[j]) {
            ++i; ++j;
            nxt[i] = j;       // 递推得到 next[i]
        } else {
            j = nxt[j];       // 失配回溯
        }
    }
}

//KMP 主过程，返回首次匹配位置（从 1 开始），失败返回 0 
int KMP(int n, int m) {
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (j == -1 || S[i] == P[j]) {
            ++i; ++j;         // 继续比较下一个字符
        } else {
            j = nxt[j];       // 失配，模式串右移
        }
    }
    if (j == m) return i - m + 1; // 匹配成功
    return 0;                     // 匹配失败
}

int main() {
    int t;
    cin >> t;                 // 实例个数
    while (t--) {
        cin >> S >> P;
        int n = strlen(S);
        int m = strlen(P);
        
        getNext(m);           // 1. 求 next 数组
        
        // 2. 按格式输出 next 数组 
        for (int i = 0; i < m; ++i) {
            cout << nxt[i];
            if (i < m) cout << ' ';
        }
        cout <<endl;
        
        // 3. 输出匹配位置 
        cout << KMP(n, m) <<endl;
    }
    return 0;
}*/
/*#include <iostream>
#include <cstring>
using namespace std;

const int N = 10005;
char S[N], P[N], R[N];   // 主串、模式串、替换串
int nxt[N];

// 经典 next 数组 
void getNext(int m) {
    int i = 0, j = -1;
    nxt[0] = -1;
    while (i < m) {
        if (j == -1 || P[i] == P[j]) {
            ++i; ++j;
            nxt[i] = j;
        } else {
            j = nxt[j];
        }
    }
}

//返回第一次匹配起点（0-based），失败返回 -1 
int KMP(int n, int m) {
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (j == -1 || S[i] == P[j]) {
            ++i; ++j;
        } else {
            j = nxt[j];
        }
    }
    return j == m ? i - m : -1;
}

// 只替换第一处 
void replaceOnce(int n, int m, int r) {
    int pos = KMP(n, m);
    if (pos == -1) {                    // 没匹配，原样输出
        cout << S << '\n';
        return;
    }
    //分段输出：匹配前 + 替换串 + 匹配后 
    for (int i = 0; i < pos; ++i) cout << S[i];
    for (int i = 0; i < r; ++i) cout << R[i];
    for (int i = pos + m; i < n; ++i) cout << S[i];
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> S >> P >> R;
        int n = strlen(S);
        int m = strlen(P);
        int r = strlen(R);
        getNext(m);

        cout << S << '\n';      // 原主串
        replaceOnce(n, m, r);   // 替换后的结果
    }
    return 0;
}*/
/*#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 100005;
char str[MAXN];      // 输入串
int nxt[MAXN];       // next 数组


int longestPrefixPostfix(char s[], int n) {
    if (n < 2) return 0;
    int i = 0, j = -1;
    nxt[0] = -1;
    while (i < n) {
        if (j == -1 || s[i] == s[j]) {
            ++i; ++j;
            nxt[i] = j;
        } else {
            j = nxt[j];
        }
    }
    return nxt[n];   // 最长真前后缀长度
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        cin >> str;
        int len = strlen(str);
        int l = longestPrefixPostfix(str, len);
        if (l == 0) {
            cout << "empty\n";
        } else {
            
            for (int i = 0; i < l; ++i) cout << str[i];
            cout << '\n';
        }
    }
    return 0;
}*///第三题
/*#include <bits/stdc++.h>
using namespace std;


int kmpCount(const string &text, const string &pattern) {
    int n = text.size(), m = pattern.size();
    if (m == 0 || n < m) return 0;


    vector<int> lps(m, 0);
    for (int i = 1, len = 0; i < m; ) {
        if (pattern[i] == pattern[len]) {
            lps[i++] = ++len;
        } else if (len) {
            len = lps[len - 1];
        } else {
            lps[i++] = 0;
        }
    }


    int cnt = 0;
    for (int i = 0, j = 0; i < n; ) {
        if (text[i] == pattern[j]) {
            ++i; ++j;
            if (j == m) {          // 找到一个完整匹配
                ++cnt;
                j = lps[j - 1];    // 允许重叠，回跳继续
            }
        } else if (j) {
            j = lps[j - 1];
        } else {
            ++i;
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    cin.ignore();
    while (t--) {
        string P;
        getline(cin, P);          // 模式串
        int N;
        cin >> N;
        cin.ignore();
        vector<string> queries(N);
        for (int i = 0; i < N; ++i) getline(cin, queries[i]);


        for (int i = 0; i < N; ++i) {
            int c = kmpCount(P, queries[i]);
            cout << queries[i] << ':' << c << '\n';
        }
    }
    return 0;
}*/ //第五题
 #include <bits/stdc++.h>
using namespace std;

/* 构造后缀数组 sa 与名次数组 rk */
void buildSA(const string &s, vector<int> &sa, vector<int> &rk) {
    int n = s.size();
    sa.resize(n);
    rk.resize(n);
    for (int i = 0; i < n; ++i) sa[i] = i, rk[i] = s[i];

    for (int k = 1; k < n; k <<= 1) {
        auto cmp = [&](int i, int j) {
            if (rk[i] != rk[j]) return rk[i] < rk[j];
            int ri = (i + k < n) ? rk[i + k] : -1;
            int rj = (j + k < n) ? rk[j + k] : -1;
            return ri < rj;
        };
        sort(sa.begin(), sa.end(), cmp);

        vector<int> tmp(n);
        tmp[sa[0]] = 0;
        for (int i = 1; i < n; ++i)
            tmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
        rk.swap(tmp);
    }
}

/* Kasai 算法求 height 数组 */
void getHeight(const string &s, const vector<int> &sa, const vector<int> &rk,
               vector<int> &height) {
    int n = s.size();
    height.resize(n);
    int k = 0;
    for (int i = 0; i < n; ++i) {
        if (rk[i] == 0) { k = 0; continue; }
        int j = sa[rk[i] - 1];
        if (k > 0) --k;
        while (i + k < n && j + k < n && s[i + k] == s[j + k]) ++k;
        height[rk[i]] = k;
    }
}

/* 二分 + 分组检查 */
int solve(const string &s) {
    int n = s.size();
    if (n == 0) return -1;

    vector<int> sa, rk, height;
    buildSA(s, sa, rk);
    getHeight(s, sa, rk, height);

    auto check = [&](int L) -> bool {
        if (L == 0) return true;
        int mn = sa[0], mx = sa[0];
        for (int i = 1; i < n; ++i) {
            if (height[i] >= L) {
                mn = min(mn, sa[i]);
                mx = max(mx, sa[i]);
                if (mx - mn >= L) return true;
            } else {
                mn = mx = sa[i];
            }
        }
        return false;
    };

    int low = 1, high = n / 2, ans = 0;
    while (low <= high) {
        int mid = (low + high) >> 1;
        if (check(mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans == 0 ? -1 : ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);
        cout << solve(s) << '\n';
    }
    return 0;
}//第四题 
