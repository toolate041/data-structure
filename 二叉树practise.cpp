#include <iostream>
using namespace std;
struct Node
{
  char data;
  Node *left;
  Node *right;
  Node(char ch) : data(ch), left(nullptr), right(nullptr) {}
};
Node *build(string str, int &i) // 重点，i要加&，所有数据共享一份数据i，能够知道i的位置
{
  if (i >= str.size() || str[i] == '0') // 当前为0或者超过了str的长度
  {
    i++;            // 跳过
    return nullptr; // 返回此节点为空
  }
  Node *node = new Node(str[i++]); // 对于当前的str值创建一个节点
  node->left = build(str, i);      // 左节点
  node->right = build(str, i);     // 右节点
  return node;
}
void preorder(Node *root)
{
  if (!root)
  {
    return;
  } // 如果遍历完了，就退出
  cout << root->data; // 根左右
  preorder(root->left);
  preorder(root->right);
}
void inorder(Node *root)
{
  if (!root)
  {
    return;
  }
  inorder(root->left); // 左根右
  cout << root->data;
  inorder(root->right);
}
void posorder(Node *root)
{
  if (!root)
  {
    return;
  }
  posorder(root->left); // 左右根
  posorder(root->right);
  cout << root->data;
}

int main()
{
  int i = 0, j, t, k;
  cin >> t;
  while (t--)
  {
    i = 0;
    string str;
    cin >> str;
    Node *node = build(str, i); // 用node接受创建好的链表
    preorder(node);
    cout << endl;
    inorder(node);
    cout << endl;
    posorder(node);
    cout << endl;
  }
}