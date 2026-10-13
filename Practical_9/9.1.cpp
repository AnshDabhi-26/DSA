#include <iostream>
using namespace std;
void dfs(int start, int **graph, bool *visited, int n) {
  visited[start] = true;
  cout << start << " ";
  for (int i = 0; i < n; i++) {
    if (graph[start][i] == 1 && visited[i] == false) {
      dfs(i, graph, visited, n);
    }
  }
}
int main() {
  int n, e;
  cout << "Enter number of buildings and roads: ";
  cin >> n >> e;
  int **graph = new int *[n];
  for (int i = 0; i < n; i++) {
    graph[i] = new int[n];
    for (int j = 0; j < n; j++) {
      graph[i][j] = 0;
    }
  }
  cout << "Enter roads (u v):\n";
  for (int i = 0; i < e; i++) {
    int u, v;
    cin >> u >> v;
    graph[u][v] = 1;
    graph[v][u] = 1;
  }
  int start;
  cout << "Enter starting building: ";
  cin >> start;
  bool *visited = new bool[n];
  for (int i = 0; i < n; i++) {
    visited[i] = false;
  }
  cout << "First team order: ";
  dfs(start, graph, visited, n);
  cout << "\n";
  cout << "Second team order: ";
  bool *visited2 = new bool[n];
  for (int i = 0; i < n; i++) {
    visited2[i] = false;
  }
  int *q = new int[n];
  int front = 0, rear = 0;
  q[rear] = start;
  rear++;
  visited2[start] = true;
  while (front < rear) {
    int curr = q[front];
    front++;
    cout << curr << " ";
    for (int i = 0; i < n; i++) {
      if (graph[curr][i] == 1 && visited2[i] == false) {
        visited2[i] = true;
        q[rear] = i;
        rear++;
      }
    }
  }
  cout << "\n";
  return 0;
}