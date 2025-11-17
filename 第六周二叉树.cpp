/*#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
    Node(char val) : data(val), left(nullptr), right(nullptr) {}
};

// 构建二叉树
Node* build(const string& pre, int& i) {
    if (i >= pre.size() || pre[i] == '#') {
        i++;
        return nullptr;
    }
    Node* node = new Node(pre[i++]);
    node->left = build(pre, i);
    node->right = build(pre, i);
    return node;
}

// 先序遍历
void preorder(Node* root) {
    if (!root) return;
    cout << root->data;
    preorder(root->left);
    preorder(root->right);
}

// 中序遍历
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data;
    inorder(root->right);
}

// 后序遍历
void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pre;
        cin >> pre;
        int i = 0;
        Node* root = build(pre, i);

        preorder(root);   cout << endl;
        inorder(root);    cout << endl;
        postorder(root);  cout << endl;
    }
    return 0#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Node {
    char data;
    Node *left, *right;
    Node(char c) : data(c), left(nullptr), right(nullptr) {}
};

int idx;
string preStr;

Node* build() {
    if (idx >= (int)preStr.size()) return nullptr;
    char c = preStr[idx++];
    if (c == '0') return nullptr;
    Node* p = new Node(c);
    p->left  = build();
    p->right = build();
    return p;
}

void levelOrder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* p = q.front(); q.pop();
        cout << p->data;
        if (p->left)  q.push(p->left);
        if (p->right) q.push(p->right);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        cin >> preStr;
        idx = 0;
        Node* root = build();
        levelOrder(root);
        cout << '\n';
    }
    return 0;
};
}*///三种次序遍历的方法
/*#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Node {
    char data;
    Node *left, *right;
    Node(char c) : data(c), left(nullptr), right(nullptr) {}
};

int idx;
string preStr;

Node* build() {
    if (idx >= (int)preStr.size()) return nullptr;
    char c = preStr[idx++];
    if (c == '0') return nullptr;
    Node* p = new Node(c);
    p->left  = build();
    p->right = build();
    return p;
}

void levelOrder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* p = q.front(); q.pop();
        cout << p->data;
        if (p->left)  q.push(p->left);
        if (p->right) q.push(p->right);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        cin >> preStr;
        idx = 0;
        Node* root = build();
        levelOrder(root);
        cout << '\n';
    }
    return 0;
}*/
/*#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node *left, *right;
    Node(char c) : data(c), left(nullptr), right(nullptr) {}
};

int leafCount;          // 全局计数器
string preStr;
int idx;

Node* build() {
    if (idx >= (int)preStr.size() || preStr[idx] == '0') {
        ++idx;
        return nullptr;
    }
    Node* p = new Node(preStr[idx++]);
    p->left  = build();
    p->right = build();
    // 刚造完左右子树，判断自己是不是叶子
    if (!p->left && !p->right) ++leafCount;
    return p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        cin >> preStr;
        idx = 0;
        leafCount = 0;
        build();           // 树建完，叶子也统计完
        cout << leafCount << '\n';
    }
    return 0;
}*///找叶子结点，就是左右孩子节点都为空 
/*
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string preStr;
int idx;

struct Node {
    char data;
    Node *left, *right;
    Node(char c) : data(c), left(nullptr), right(nullptr) {}
};

// 先序建二叉树
Node* build() {
    if (idx >= (int)preStr.size() || preStr[idx] == '0') {
        ++idx;
        return nullptr;
    }
    Node* p = new Node(preStr[idx++]);
    p->left  = build();
    p->right = build();
    return p;
}

// 后序递归求高度
int height(Node* p) {
    if (!p) return 0;
    return max(height(p->left), height(p->right)) + 1;
}

int main() {

    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        cin >> preStr;
        idx = 0;
        Node* root = build();
        cout << height(root) << '\n';
    }
    return 0;
}*/
/*#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char v) : val(v), left(nullptr), right(nullptr) {}
};

int index = 0;

TreeNode* buildTree(const string& s) {
    if (index >= s.size() || s[index] == '0') {
        index++;
        return nullptr;
    }
    TreeNode* root = new TreeNode(s[index++]);
    root->left = buildTree(s);
    root->right = buildTree(s);
    return root;
}

void findLeaves(TreeNode* node, TreeNode* parent, vector<char>& leaves, vector<char>& parents) {
    if (!node) return;
    if (!node->left && !node->right) {
        leaves.push_back(node->val);
        parents.push_back(parent ? parent->val : '0');
    }
    findLeaves(node->left, node, leaves, parents);
    findLeaves(node->right, node, leaves, parents);
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; ++i) {
        string s;
        getline(cin, s);
        index = 0;
        TreeNode* root = buildTree(s);
        vector<char> leaves, parents;
        findLeaves(root, nullptr, leaves, parents);

        for (size_t j = 0; j < leaves.size(); ++j) {
            cout << leaves[j] << " ";
        }
        cout << endl;

        for (size_t j = 0; j < parents.size(); ++j) {
            cout << parents[j] << " ";
        }
        cout << endl;
    }
    return 0;
}*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int v): val(v), left(nullptr), right(nullptr) {}
};

// 用数组 a 建普通二叉树，返回根
Node* build(const vector<int>& a, int i) {
    if (i >= (int)a.size() || a[i] == 0) return nullptr;
    Node* root = new Node(a[i]);
    root->left  = build(a, 2*i + 1);
    root->right = build(a, 2*i + 2);
    return root;
}

// 先序遍历，每个值后都加空格
void pre(Node* root) {
    if (!root) return;
    cout << root->val << ' ';
    pre(root->left);
    pre(root->right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        Node* root = build(a, 0);
        pre(root);
        cout << '\n';
    }
    return 0;
}
