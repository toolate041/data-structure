#include <iostream>
using namespace std;
int cnt = 0;
struct Node
{
  char data;
  Node *left;
  Node *right;
  Node(char ch) : data(ch), left(nullptr), right(nullptr) {}
};
Node *build(string str, int &i)
{
  if (i >= str.size() || str[i] == '0')
  {
    i++;
    return nullptr;
  }
  Node *node = new Node(str[i++]);
  node->left = build(str, i);
  node->right = build(str, i);
  return node;
} // 构造二叉树
void findleaves(Node *root)
{

  if (!root)
  {
    return;
  } // 不可少，空树就返回
  if (root->left == nullptr && root->right == nullptr)
  {
    cnt++;
    return;
  } // 计数器
  findleaves(root->left); // 对每个节点都要找
  findleaves(root->right);
}
int main()
{
  int i, j, t, k;
  string str;
  cin >> t;
  while (t--)
  {

    k = 0;
    cnt = 0;
    cin >> str;
    Node *node = build(str, k);
    findleaves(node);
    cout << cnt << endl;
  }
}
/*
计算一颗二叉树包含的叶子结点数量。

提示：叶子是指它的左右孩子为空。

建树方法采用“先序遍历+空树用0表示”的方法，即给定一颗二叉树的先序遍历的结果为AB0C00D00，其中空节点用字符‘0’表示。
输入

第一行输入一个整数t，表示有t个测试数据

第二行起输入二叉树先序遍历的结果，空树用字符‘0’表示，输入t行


输出

逐行输出每个二叉树的包含的叶子数量

输入样例:
3
AB0C00D00
AB00C00
ABC00D00E00
输出样例：
2
2
3
*/