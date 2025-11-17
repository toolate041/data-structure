/*#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        vector<char> val(n);
        for (int i = 0; i < n; ++i) cin >> val[i];
        vector<int> parent(n);
        for (int i = 0; i < n; ++i) cin >> parent[i];

        // 1. 建树 
        vector<vector<int>> children(n);
        int root = -1;
        for (int i = 0; i < n; ++i)
            if (parent[i] == -1)
                root = i;
            else
                children[parent[i]].push_back(i);

        //2. 先根遍历（栈模拟） 
        string ans;
        ans.reserve(n);
        stack<int> st;
        st.push(root);
        while (!st.empty()) {
            int u = st.top();
            st.pop();
            ans.push_back(val[u]);
            //逆序入栈，保证出栈时从左到右 
            for (auto it = children[u].rbegin(); it != children[u].rend(); ++it)
                st.push(*it);
        }
        cout << ans << '\n';
    }
    return 0;
}*/
/*#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, r;
    cin >> n >> r;
    vector<char> val(n);
    vector<vector<int>> children(n);

    for (int i = 0; i < n; ++i) {
        cin >> val[i];
        int x;
        while (cin >> x && x != -1) children[i].push_back(x);
    }

    // 栈模拟后根遍历 
    string ans;
    ans.reserve(n);
    stack<pair<int, bool>> st;   // bool = true 表示已处理过孩子
    st.emplace(r, false);

    while (!st.empty()) {
        auto [u, done] = st.top();
        st.pop();
        if (done) {                // 第二次遇到，输出
            ans.push_back(val[u]);
            continue;
        }
        st.emplace(u, true);       // 重新入栈，标记已处理
        // 逆序压孩子，保证左→右顺序 
        for (auto it = children[u].rbegin(); it != children[u].rend(); ++it)
            st.emplace(*it, false);
    }

    cout << ans << '\n';
    return 0;
}*/
/*#include <bits/stdc++.h>
using namespace std;

struct Node {
    char val;
    Node *l, *r;
    Node(char c): val(c), l(nullptr), r(nullptr) {}
};

// 先序重建，返回根指针 
Node* build(const string &s, int &p) {
    if (p == (int)s.size() || s[p] == '#') {
        ++p;
        return nullptr;
    }
    Node *node = new Node(s[p++]);
    node->l = build(s, p);
    node->r = build(s, p);
    return node;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        int p = 0;
        Node *root = build(line, p);

        // BFS 重新编号（层次顺序），并记录父结点 
        vector<char> vals;
        vector<int> par;
        queue<pair<Node*, int>> q;   // (结点, 父编号)
        q.push({root, -1});
        while (!q.empty()) {
            auto [u, fa] = q.front(); q.pop();
            int id = vals.size();    // 当前结点编号
            vals.push_back(u->val);
            par.push_back(fa);
            if (u->l) q.push({u->l, id});
            if (u->r) q.push({u->r, id});
        }

        /* 输出 
        for (size_t i = 0; i < vals.size(); ++i) {
            if (i) cout << ' ';
            cout << vals[i];
        }
        cout << '\n';
        for (size_t i = 0; i < par.size(); ++i) {
            if (i) cout << ' ';
            cout << par[i];
        }
        cout << '\n';
    }
    return 0;
}*/
/*
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<char> data(n);          // 结点值
    for (int i = 0; i < n; ++i) cin >> data[i];

    vector<int> parent(n);         // 双亲下标
    for (int i = 0; i < n; ++i) cin >> parent[i];

    vector<vector<int>> children(n); // 孩子链表
    for (int i = 0; i < n; ++i)
        if (parent[i] != -1)       // 非根结点
            children[parent[i]].push_back(i);

    // 按结点顺序输出
    for (int i = 0; i < n; ++i) {
        cout << data[i];           // 先输出结点值
        if (children[i].empty()) {
            cout << " -1 ";
        } else {
            for (int ch : children[i]) cout << ' ' << ch;
            cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}
*/ 
/*
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string pre, in;
int N;

struct Node {
    char val;
    Node *lc, *rc;
    Node(char v): val(v), lc(nullptr), rc(nullptr) {}
};

// 递归重建：pre[l1..r1] 和 in[l2..r2] 对应同一棵子树
Node* build(int l1, int r1, int l2, int r2) {
    if (l1 > r1) return nullptr;
    char rootv = pre[l1];
    Node* root = new Node(rootv);
    int k = l2;
    while (in[k] != rootv) ++k;          // 根在中序中的位置
    int leftSize = k - l2;               // 左子树大小
    root->lc = build(l1 + 1, l1 + leftSize, l2, k - 1);
    root->rc = build(l1 + leftSize + 1, r1, k + 1, r2);
    return root;
}

// 后序遍历方式求高度（避免全局变量）
int height(Node* p) {
    if (!p) return 0;
    int lh = height(p->lc);
    int rh = height(p->rc);
    return max(lh, rh) + 1;
}

int main() {
    cin >> N;
    cin >> pre >> in;
    Node* root = build(0, N - 1, 0, N - 1);
    cout << height(root) << endl;
    return 0;
}
*/

