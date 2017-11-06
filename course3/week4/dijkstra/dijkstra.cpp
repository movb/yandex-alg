#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <functional>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;

int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  //write your code her
  vector<int> dist(adj.size(), std::numeric_limits<int>::max());
  dist[s] = 0;
  vector<int> processed(adj.size(), 0);
  priority_queue<pair<int,int>, vector<pair<int,int>>, std::greater<pair<int,int>>> q;
  for(int i=0; i<dist.size(); ++i)
      q.emplace( dist[i], i );
  
  while(!q.empty()) {
      int u = q.top().second;
      q.pop();
      if(processed[u])
          continue;
      if(dist[u] == std::numeric_limits<int>::max())
          break;
      processed[u] = 1;
      for(int j=0; j<adj[u].size(); ++j) {
          if (dist[adj[u][j]] > (dist[u] + cost[u][j])) {
              dist[adj[u][j]] = dist[u] + cost[u][j];
              q.emplace(dist[adj[u][j]], adj[u][j]);
          }
      }
  }
          
  return dist[t] == std::numeric_limits<int>::max() ? -1 : dist[t];
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
