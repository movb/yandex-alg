#include <iostream>
#include <vector>

using std::vector;
using std::pair;

bool explore(vector<vector<int> > &adj, vector<bool> &removed, vector<bool>& visited, int i)
{
    visited[i] = true;
    for(int j = 0; j < adj[i].size(); j++) {
        if( removed[adj[i][j]] )
            continue;

        if( visited[adj[i][j]] )
            return true;

        if(explore(adj, removed, visited, adj[i][j]))
            return true;
    }
    removed[i] = true;

    return false;
}



int acyclic(vector<vector<int> > &adj) {
  //write your code here
  vector<bool> removed(adj.size(), false);

  for(int i=0; i < adj.size(); ++i)
  {
      if(removed[i])
          continue;
      vector<bool> visited(adj.size(), false);
      if(explore(adj, removed, visited, i))
          return 1;
  }

  return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj);
}
