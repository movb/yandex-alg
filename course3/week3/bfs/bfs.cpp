#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;
using std::make_pair;

int distance(vector<vector<int> > &adj, int s, int t) {
  //write your code here
  queue<int> q;
  vector<int> dist(adj.size(), -1);
  dist[s] = 0;
  q.push(s);

  while(!q.empty())
  {
      auto v = q.front();
      q.pop();

      for(int i=0; i<adj[v].size(); ++i)
      {
          if(dist[adj[v][i]] == -1) {
              q.push(adj[v][i]);
              dist[adj[v][i]] = dist[v] + 1;
          }
      }
  }

  return dist[t];
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
