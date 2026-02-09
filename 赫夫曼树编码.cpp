#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAXN = 20010;  // 最多可能有2n个节点

struct Node {
    int weight;   // 权值
    int parent;   // 父节点索引
    int left;     // 左孩子索引
    int right;    // 右孩子索引
};

Node tree[MAXN];  // 哈夫曼树节点数组
string codes[MAXN];  // 存储每个叶子节点的编码
int n;  // 叶子节点数量

// 生成哈夫曼编码的递归函数
void generateCodes(int node, string code) {
    // 如果是叶子节点（左右孩子都为0）
    if (tree[node].left == 0 && tree[node].right == 0) {
        codes[node] = code;  // 存储编码
        return;
    }
    
    // 递归处理左子树（编码加"0"）
    if (tree[node].left != 0)
        generateCodes(tree[node].left, code + "0");
    
    // 递归处理右子树（编码加"1"）
    if (tree[node].right != 0)
        generateCodes(tree[node].right, code + "1");
}

int main() {
    // 输入叶子节点数量
    cin >> n;
    
    // 初始化前n个节点（叶子节点）
    for (int i = 1; i <= n; i++) {//循环从1开始，0的位置是空值
        cin >> tree[i].weight;  // 输入权值
        tree[i].parent = 0;      // 初始时没有父节点
        tree[i].left = 0;        // 初始时没有左孩子
        tree[i].right = 0;       // 初始时没有右孩子
    }
    
    int totalNodes = n;  // 当前总节点数
    
    // 构建哈夫曼树，需要n-1次合并
    for (int i = 1; i < n; i++) 
    {
        int min1 = 0, min2 = 0;  // 最小的两个节点索引
        
        // 在所有没有父节点的节点中找最小的两个
        for (int j = 1; j <= totalNodes; j++) {
            if (tree[j].parent == 0) {  // 只考虑没有父节点的节点
                // 找最小值min1
                if (min1 == 0 || tree[j].weight < tree[min1].weight) {
                    min2 = min1;  // 原来的min1变成min2
                    min1 = j;     // 更新min1
                }
                // 找次小值min2
                else if (min2 == 0 || tree[j].weight < tree[min2].weight) {
                    min2 = j;     // 更新min2
                }
            }
        }
        
        // 确保左孩子权值不大于右孩子（题目要求）
        //if (tree[min1].weight > tree[min2].weight)
           // swap(min1, min2);
        
        // 创建新节点
        totalNodes++;  // 节点索引加1
        // 新节点的权值是min1和min2权值之和
        tree[totalNodes].weight = tree[min1].weight + tree[min2].weight;
        tree[totalNodes].left = min1;    // 左孩子是min1
        tree[totalNodes].right = min2;   // 右孩子是min2
        tree[totalNodes].parent = 0;     // 新节点还没有父节点
        
        // 设置min1和min2的父节点为新节点
        tree[min1].parent = totalNodes;
        tree[min2].parent = totalNodes;
    }
    
    // 从根节点开始生成编码（根节点是最后一个节点）
    generateCodes(totalNodes, "");
    
    // 输出每个权值对应的编码
    for (int i = 1; i <= n; i++) {
        cout << tree[i].weight << "-" << codes[i] << endl;
    }
    
    return 0;
}