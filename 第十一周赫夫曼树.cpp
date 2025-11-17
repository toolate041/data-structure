/*#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int MAXN = 10005;

struct Node {
    int weight;
    int parent;
    int left;
    int right;
};

Node tree[2 * MAXN];
int n;

// 用于存放每个权值的编码
vector<string> codes(MAXN);

// 递归生成Huffman编码
void generateCodes(int node, string code) {
    if (tree[node].left == 0 && tree[node].right == 0) {
        // 叶子节点
        codes[node] = code;
        return;
    }
    if (tree[node].left != 0)
        generateCodes(tree[node].left, code + "0");
    if (tree[node].right != 0)
        generateCodes(tree[node].right, code + "1");
}

int main() {
    cin >> n;

    // 初始化树节点
    for (int i = 1; i <= n; i++) {
        cin >> tree[i].weight;
        tree[i].parent = 0;
        tree[i].left = 0;
        tree[i].right = 0;
    }

    int totalNodes = n;

    // 构造Huffman树
    for (int i = 1; i < n; i++) {
        int min1 = 0, min2 = 0;

        // 找到第一个没有父节点的节点作为min1
        for (int j = 1; j <= totalNodes; j++) {
            if (tree[j].parent == 0) {
                if (min1 == 0 || tree[j].weight < tree[min1].weight) {
                    min2 = min1;
                    min1 = j;
                } else if (min2 == 0 || tree[j].weight < tree[min2].weight) {
                    min2 = j;
                }
            }
        }

        // 确保左孩子权值不大于右孩子
        if (tree[min1].weight > tree[min2].weight)
            swap(min1, min2);

        totalNodes++;
        tree[totalNodes].weight = tree[min1].weight + tree[min2].weight;
        tree[totalNodes].left = min1;
        tree[totalNodes].right = min2;
        tree[totalNodes].parent = 0;

        tree[min1].parent = totalNodes;
        tree[min2].parent = totalNodes;
    }

    // 生成Huffman编码
    generateCodes(totalNodes, "");

    // 输出每个权值对应的编码
    for (int i = 1; i <= n; i++) {
        cout << tree[i].weight << "-" << codes[i] << endl;
    }

    return 0;
}
*/
/*
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int MAXN = 10005;
const int ok = 1;
const int error = -1;

struct Node {
    int weight;
    int parent;
    int left;
    int right;
    char ch;          // 只有叶子节点用到
};

Node tree[2 * MAXN];   // 1..2*n-1
int n, root;           // root 记录根节点编号

/* 解码函数：输入编码串，输出解码串，成功返回 ok，失败返回 error 
int Decode(const string codestr, char txtstr[]) {
    int p = root;                  // 从根出发
    int outLen = 0;                // 已写入 txtstr 的下标
    int len = codestr.size();

    for (int i = 0; i < len; ) {
        char ch = codestr[i];
        if (ch == '0')             // 左孩子
            p = tree[p].left;
        else if (ch == '1')        // 右孩子
            p = tree[p].right;
        else                       // 非法字符
            return error;

        if (p == 0)                // 走到空指针，树结构异常
            return error;

        // 如果到达叶子
        if (tree[p].left == 0 && tree[p].right == 0) {
            txtstr[outLen++] = tree[p].ch; // 输出字符
            p = root;                      // 回到根继续
        }
        ++i;
    }

    // 循环结束必须回到根，否则还有未走完的节点
    if (p != root)
        return error;

    txtstr[outLen] = '\0'; // 字符串结束符
    return ok;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> tree[i].weight;
        tree[i].parent = tree[i].left = tree[i].right = 0;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> tree[i].ch;
    }

    /* 构造 Huffman 树 
    int totalNodes = n;
    for (int i = 1; i < n; ++i) {
        int min1 = 0, min2 = 0;
        for (int j = 1; j <= totalNodes; ++j) {
            if (tree[j].parent == 0) {
                if (min1 == 0 || tree[j].weight < tree[min1].weight) {
                    min2 = min1;
                    min1 = j;
                } else if (min2 == 0 || tree[j].weight < tree[min2].weight) {
                    min2 = j;
                }
            }
        }
        // 保证左子树权值 <= 右子树权值
        if (tree[min1].weight > tree[min2].weight)
            swap(min1, min2);

        ++totalNodes;
        tree[totalNodes].weight = tree[min1].weight + tree[min2].weight;
        tree[totalNodes].left  = min1;
        tree[totalNodes].right = min2;
        tree[totalNodes].parent = 0;
        tree[min1].parent = totalNodes;
        tree[min2].parent = totalNodes;
    }
    root = totalNodes; // 根节点编号

    int k;
    cin >> k;
    while (k--) {
        string codestr;
        cin >> codestr;
        char txtstr[MAXN];
        if (Decode(codestr, txtstr) == ok)
            cout << txtstr << '\n';
        else
            cout << "error\n";
    }
    return 0;
}*/
/*#include <iostream>
#include <cstring>
using namespace std;

const int MAXV = 105;       // 最大顶点数
int adj[MAXV][MAXV];        // 邻接矩阵
int degree[MAXV];           // 度（无向图）
int outDeg[MAXV], inDeg[MAXV]; // 有向图出度、入度
char type;                  // 'D' 或 'U'
int n, m;                   // 顶点数、边数
char vertex[MAXV][10];      // 顶点名字符串数组

// 根据名字找下标
int findIndex(const char name[]) {
    for (int i = 0; i < n; ++i)
        if (strcmp(vertex[i], name) == 0) return i;
    return -1;
}

void solve() {
    cin >> type >> n;
    for (int i = 0; i < n; ++i) cin >> vertex[i];

    // 初始化
    memset(adj, 0, sizeof(adj));
    memset(degree, 0, sizeof(degree));
    memset(outDeg, 0, sizeof(outDeg));
    memset(inDeg, 0, sizeof(inDeg));

    cin >> m;
    char u[10], v[10];
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        int ui = findIndex(u);
        int vi = findIndex(v);
        if (type == 'D') {          // 有向图
            adj[ui][vi] = 1;
            outDeg[ui]++;
            inDeg[vi]++;
        } else {                    // 无向图
            adj[ui][vi] = 1;
            adj[vi][ui] = 1;
            degree[ui]++;
            degree[vi]++;
        }
    }

    // 1. 输出邻接矩阵
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << adj[i][j];
            if (j + 1 < n) cout << ' ';
        }
        cout << '\n';
    }

    // 2. 输出度信息
    if (type == 'D') {
        for (int i = 0; i < n; ++i)
            if (outDeg[i] + inDeg[i] > 0)   // 不输出孤立点
                cout << vertex[i] << ": " << outDeg[i] << ' ' << inDeg[i] << ' ' << (outDeg[i] + inDeg[i]) << '\n';
    } else {
        for (int i = 0; i < n; ++i)
            if (degree[i] > 0)
                cout << vertex[i] << ": " << degree[i] << '\n';
    }

    // 3. 输出孤立点（度为0）
    bool hasIso = false;
    for (int i = 0; i < n; ++i) {
        int d = (type == 'D') ? (outDeg[i] + inDeg[i]) : degree[i];
        if (d == 0) {
            if (!hasIso) {
                cout <<  vertex[i];
                hasIso = true;
            } else {
                cout << ' ' << vertex[i];
            }
        }
    }
    if (hasIso) cout << '\n';
}

int main() {


    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}*/
#include <iostream>
#include <cstring>
using namespace std;

const int MAXV = 105;
const int MAXE = 1005;

struct ArcNode {
    int adjvex;        // 弧头顶点在数组中的下标
    ArcNode *next;
};

struct VNode {
    char info[10];     // 顶点编号
    ArcNode *first;    // 邻接表头指针
};

VNode adjlist[MAXV];
int n, k;

// 根据顶点名字返回下标
int findIndex(const char name[]) {
    for (int i = 0; i < n; ++i)
        if (strcmp(adjlist[i].info, name) == 0) return i;
    return -1;
}

// 尾插法建邻接表，保证顺序与输入一致
void build() {
    for (int i = 0; i < n; ++i) adjlist[i].first = nullptr;

    for (int i = 0; i < k; ++i) {
        char u[10], v[10];
        cin >> u >> v;
        int ui = findIndex(u);
        int vi = findIndex(v);

        ArcNode *p = new ArcNode;
        p->adjvex = vi;
        p->next = nullptr;

        if (adjlist[ui].first == nullptr) {
            adjlist[ui].first = p;
        } else {
            ArcNode *q = adjlist[ui].first;
            while (q->next) q = q->next;
            q->next = p;
        }
    }
}

// 按格式输出邻接表
void print() {
    for (int i = 0; i < n; ++i) {
        cout << i << ' ' << adjlist[i].info;
        for (ArcNode *p = adjlist[i].first; p; p = p->next)
            cout << '-' << p->adjvex;
        cout << "-^\n";
    }
}

// 释放链表内存
void clear() {
    for (int i = 0; i < n; ++i) {
        ArcNode *p = adjlist[i].first;
        while (p) {
            ArcNode *tmp = p;
            p = p->next;
            delete tmp;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            cin >> adjlist[i].info;
            adjlist[i].first = nullptr;
        }
        build();
        print();
        clear();
    }
    return 0;
}
