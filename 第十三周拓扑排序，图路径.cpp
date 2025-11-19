/*#include <iostream>
using namespace std;
int check(int arr[100][100], int m, bool checked[100])
{
  int i, j, k, flag = 0;
  for (i = 0; i < m; i++)
  {
    flag = 0;
    for (j = 0; j < m; j++)
    {
      if (arr[j][i] == 1)
      {
        flag = 1;
        break;
      }
    }
    if (!flag && checked[i] == false)
    {
      return i;
    }
  }
}
int kong(int arr[100][100], int m)
{
  int i, j, t, k, flag = 0;
  for (i = 0; i < m; i++)
  {
    for (j = 0; j < m; j++)
    {
      if (arr[i][j])
      {
        flag = 1;
        return 0;
      }
    }
  }
  if (!flag)
  {
    return 1; // 空了就是1
  }
}
void qingkong(int arr[100][100], int m, int g)
{
  int i, j;
  for (i = 0; i < m; i++)
  {
    arr[g][i] = 0;
  }
}
void tuopu(int arr[100][100], int m, bool visited[100])
{
  int i, j, k;
  int g = check(arr, m, visited);
  cout << g << " ";
  visited[g] = true;
  qingkong(arr, m, g);
  int f = kong(arr, m);
  if (!f)
  {
    tuopu(arr, m, visited);
  }
}
int main()
{
  int n, m, i, j;
  cin >> n;
  while (n--)
  {
    cin >> m;
    int arr[100][100] = {0};
    for (i = 0; i < m; i++)
    {
      for (j = 0; j < m; j++)
      {
        cin >> arr[i][j];
      }
    } // 读取数组
    bool visited[100] = {false}; //
    tuopu(arr, m, visited);
    for(i=0;i<m;i++)
    {
      if(visited[i]!=true)
      {
        cout<<i<<" ";
      }
    }
    cout<<endl;
  }
}
  */
// first拓扑算法
#include <iostream>
#include <cstring>
using namespace std;

const int MAXV = 105;
const int MAXE = 10005;
const int INF = 0x3f3f3f3f;

int n, m;
int head[MAXV], nxt[MAXE], to[MAXE], w[MAXE], tot;
int inDeg[MAXV], topo[MAXV], cntTopo;
int ve[MAXV], vl[MAXV];

// 手工栈版拓扑排序
int stk[MAXV], top;

void addEdge(int u, int v, int len)
{
  ++tot;
  nxt[tot] = head[u];
  to[tot] = v;
  w[tot] = len;
  head[u] = tot;
  ++inDeg[v];
}

bool topoSort()
{
  top = 0;
  for (int i = 0; i < n; ++i)
    if (inDeg[i] == 0)
      stk[top++] = i;

  cntTopo = 0;
  while (top)
  {
    int u = stk[--top];
    topo[cntTopo++] = u;
    for (int e = head[u]; e; e = nxt[e])
    {
      int v = to[e];
      if (--inDeg[v] == 0)
        stk[top++] = v;
    }
  }
  return cntTopo == n;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for (int i = 0; i < m; ++i)
  {
    int u, v, len;
    cin >> u >> v >> len;
    addEdge(u, v, len);
  }

  // 1. 求最早开始时间 ve[]
  memset(ve, 0, sizeof(ve));
  if (!topoSort())
    return 0; // 题目保证无环，可省略处理

  for (int i = 0; i < cntTopo; ++i)
  {
    int u = topo[i];
    for (int e = head[u]; e; e = nxt[e])
    {
      int v = to[e];
      if (ve[u] + w[e] > ve[v])
        ve[v] = ve[u] + w[e];
    }
  }

  // 2. 求最迟开始时间 vl[]
  for (int i = 0; i < n; ++i)
    vl[i] = ve[topo[cntTopo - 1]];
  for (int i = cntTopo - 1; i >= 0; --i)
  {
    int u = topo[i];
    for (int e = head[u]; e; e = nxt[e])
    {
      int v = to[e];
      if (vl[v] - w[e] < vl[u])
        vl[u] = vl[v] - w[e];
    }
  }

  // 3. 输出
  // 3. 输出
  for (int i = 0; i < n; ++i)
    cout << ve[i] << ' ';
  cout << '\n';
  for (int i = 0; i < n; ++i)
    cout << vl[i] << ' ';
  cout << '\n';

  return 0;
} // 有图无环，关键路径
