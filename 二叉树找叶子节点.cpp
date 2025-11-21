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