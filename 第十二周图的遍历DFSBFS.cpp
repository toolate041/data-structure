/*
#include <iostream>
using namespace std;
void visit(int m)
{
  cout << m << " ";
}
void DFS(int arr[100][100], int v, bool visited[100], int a)
{
  visit(v);
  visited[v] = true; // 进来的先被遍历了
  int i, j;
  for (i = 0; i < a; i++)
  {
    if (arr[v][i] == 1 && visited[i] == false)
    {
      DFS(arr, i, visited, a); // 通过一个元素，找下一个元素的方法一般用递归
    }
  }
}
int main()
{
  int t, a, i, j;
  cin >> t;
  while (t--)
  {
    cin >> a;
    int arr[100][100] = {0};
    for (i = 0; i < a; i++)
    {
      for (j = 0; j < a; j++)
      {
        cin >> arr[i][j];
      }
    }
    bool visited[100] = {false};
    DFS(arr, 0, visited, a);
    cout << endl;
  }
}
*/

/*
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int Q[100] = {0};
int head = 0;
int tail = 0;
void visit(int m)
{
  cout << m << " ";
}
void Enqueue(int m)
{
  Q[tail++] = m; // 入队操作，用tail往后面插
}
void Dequeue(int &m)
{
  m = Q[head++]; // 出队操作，用tail从前面读，&相当于直接返回了这个值
}
bool issEmpty()
{
  return head == tail; // 检查队列是否为空
}
void BFS(int arr[100][100], int v, bool visited[100], int a)
{
  head = tail = 0;
  int i, j;
  visit(v);
  visited[v] = true; // 先进来的读取
  Enqueue(v);        // 读取的入队
  while (issEmpty() == false)
  {
    Dequeue(v); // 出队，以该元素为起点，找他的节点
    for (i = 0; i < a; i++)
    {
      if (arr[v][i] == 1 && visited[i] == false)
      {
        visit(i);
        visited[i] = true;
        Enqueue(i); // 找到了节点就入队
      }
    }
    // 放在一个循环里，当所有的元素都出队了就结束了，不用递归
  }
}
int main()
{
  int a, t, i, j;
  cin >> t;
  while (t--)
  {
    cin >> a;
    int arr[100][100] = {0};
    for (i = 0; i < a; i++)
    {
      for (j = 0; j < a; j++)
      {
        cin >> arr[i][j];
      }
    } // 读取数组
    bool visited[100] = {false}; // 判断元素是否被遍历
    BFS(arr, 0, visited, a);
    cout << endl;
  }
}

*/
/*
#include <iostream>
using namespace std;
void output(int arr[100][100], int a)
{
  int i, j;
  for (i = 0; i < a; i++)
  {
    for (j = 0; j < a - 1; j++)
    {
      cout << arr[i][j] << " ";
    }
    cout << arr[i][j] << endl;
  }
}
void output(string arr[100], int a)
{
  int i, j;
  for (i = 0; i < a - 1; i++)
  {
    cout << arr[i] << " ";
  }
  cout << arr[i] << endl;
}
void DFS(int arr[100][100], bool visited[100], int v, int n)
{                                 // 普通 DFS
  visited[v] = true;              // 传入的值先被遍历
  for (int i = 0; i < n; ++i)     // 循环
    if (arr[v][i] && !visited[i]) // 传入的值做横坐标，找纵坐标，为1 且未被遍历的进行DFS
      DFS(arr, visited, i, n);
} // 牢记，常见的DFS写法，用到递归，传入的参数包括领接矩阵，遍历数组，判断值以及元素个数
int main()
{
  int a, t, i, j, num;
  cin >> t;
  while (t--)
  {
    cin >> a;
    string point[100];
    int arr[100][100] = {0};
    for (i = 0; i < a; i++)
      cin >> point[i];
    cin >> num;
    output(point, a);
    while (num--)
    {
      int flag = 0, flag2 = 0;
      string k, p;
      cin >> k >> p;
      for (i = 0; i < a; i++)
      {
        if (point[i] == k)
          flag = i;
        if (point[i] == p)
          flag2 = i;
      }
      arr[flag][flag2] = 1;
      arr[flag2][flag] = 1; // 生成领接矩阵
    }
    output(arr, a);
    // 找连通分量
    bool visited[100] = {0};
    int comp = 0;
    for (i = 0; i < a; i++)
    {
      if (!visited[i])
      {
        DFS(arr, visited, i, a); // 有多少个联通分量，就有多少个DFS
        comp++;
      }
    }
    cout << comp << endl;
    cout << endl;
  }
}
*/
