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
void findleaves(Node *root, char arr[100])
{

  if (!root)
  {
    return;
  } // 不可少，空树就返回
  if (root->left == nullptr && root->right == nullptr)
  {
    arr[cnt] = root->data;
    cnt++;
    return;
  } // 计数器
  findleaves(root->left, arr); // 对每个节点都要找
  findleaves(root->right, arr);
}
// void findpa(Node *root,char arr)
// {

//     if(root->left->data==arr||root->right->data==arr)
//     {
//       cout<<root->data<<" ";
//       return;
//     }
//     findpa(root->left,arr);
//     findpa(root->right,arr);

// }//有问题，在这里root->left如果为空，那么root->left->data就识别不到，同时会死循环
// 对遍历此表来说，要加退出条件，
bool findpa(Node *root, char arr)
{
  if (!root || (!root->left && !root->right)) // 要是左右子树都为0，就不用找了
  {
    return false;
  }
  if ((root->left && root->left->data == arr) || (root->right && root->right->data == arr)) // root->left必须要写，要确保左节点存在
  {
    cout << root->data << " ";
    return true;
  }
  return findpa(root->left, arr) || findpa(root->right, arr); // 递归的方法
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
    char arr[100] = {0};
    cin >> str;
    Node *node = build(str, k);
    findleaves(node, arr);
    for (i = 0; i < cnt; i++)
      cout << arr[i] << " ";
    cout << endl;
    for (i = 0; i < cnt; i++)
    {
      findpa(node, arr[i]);
    }
    cout << endl;
  }
}

/*
给定一颗二叉树的逻辑结构如下图，（先序遍历的结果，空树用字符‘0’表示，例如AB0C00D00），建立该二叉树的二叉链式存储结构。

编写程序输出该树的所有叶子结点和它们的父亲结点
输入

第一行输入一个整数t，表示有t个二叉树

第二行起，按照题目表示的输入方法，输入每个二叉树的先序遍历，连续输入t行


输出

第一行按先序遍历，输出第1个示例的叶子节点

第二行输出第1个示例中与叶子相对应的父亲节点

以此类推输出其它示例的结果

输入：
3
AB0C00D00
AB00C00
ABCD0000EF000
输出：
C D
B A
B C
A A
D F
C E
*/