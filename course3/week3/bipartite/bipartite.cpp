#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int bipartite(vector<vector<int> > &adj) {
  //write your code here
  vector<int> color(adj.size(), -1);
  queue<int> q;
  q.push(0);
  color[0] = 0;

  while(!q.empty()) {
      int v = q.front();
      q.pop();

      for(int i=0; i<adj[v].size(); ++i)
      {
          if (color[adj[v][i]] == -1) {
              color[adj[v][i]] = ((color[v] + 1) % 2);
              q.push(adj[v][i]);
          }
          else {
              if (color[adj[v][i]] != ((color[v] + 1) % 2))
                  return 0;
          }
      }
  }

  return 1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << bipartite(adj);
}
