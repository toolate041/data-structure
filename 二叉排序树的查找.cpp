#include<iostream>
using namespace std;
int cnt=0;
struct Node
{
  int key;
  Node *left;
  Node *right;
  Node(int m):left(nullptr),right(nullptr),key(m){}
};
Node *build(Node *node,int key)
{
  if(!node)
  {
    return new Node(key);
  }
  if(key<node->key)
  {
    node->left=build(node->left,key);
  }
  else if(key>node->key)
  {
    node->right=build(node->right,key);
  }
  return node;
}
void inorder(Node *node)
{
  if(!node)
  {
    return;
  }
  inorder(node->left);
  cout<<node->key<<" ";
  inorder(node->right);
}
void Find(Node *node,int key)
{

  if(!node)
  {
    return;
  }
  if(key<node->key)
  {
    cnt++;
    Find(node->left,key);
  }
  else if(key>node->key)
  {
    cnt++;
    Find(node->right,key);
  }
  else
  {
    cnt++;
    cout<<cnt<<endl;
    return;
  }
}
int main()
{
  int i,j,k,t,num,number,key,find;
  int a[100];
  cin>>t;
  Node *node=nullptr;
  for(i=0;i<t;i++)
  {
    cin>>a[i];
    node=build(node,a[i]);
  }
  inorder(node);
  cout<<endl;
  cin>>number;
  for(i=0;i<number;i++)
  {
    cnt=0;
    cin>>find;
    int flag=0;
    for(j=0;j<t;j++)
    {
      if(find==a[j])
      {
        flag=1;
        break;
      }
    }
    if(!flag)
    {
      cout<<"-1"<<endl;
    }
    else
    Find(node,find);
  }
}