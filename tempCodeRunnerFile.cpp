#include <iostream>
using namespace std;
void visit(int m)
{
  cout << m << " ";
}
void DFS(int arr[100][100], int v, bool visited[100], int a)
{
  visit(v);
  visited[v] = true;
  int i, j;
  for (i = 0; i < a; i++)
  {
    if (arr[v][i] == 1 && visited[i] == false)
    {
      DFS(arr, i, visited, a);
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
    bool visited[100];
    DFS(arr, 0, visited, a);
    cout << endl;
  }
}