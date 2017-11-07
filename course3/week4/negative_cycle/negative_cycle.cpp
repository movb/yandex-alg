#include <iostream>
#include <vector>
#include <limits>

using std::vector;
using std::numeric_limits;

int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
  //write your code here
  vector<int> processed(adj.size(), 0);
  
  for(int i=0; i<adj.size(); ++i) {
      if (processed[i])
          continue;

      vector<int> dist(adj.size(), numeric_limits<int>::max());
      dist[i] = 0;
      
      for(int j=0; j<adj.size()-1; ++j)
      {
          for(int k=0; k<adj.size(); ++k) {
              if (dist[k] == numeric_limits<int>::max())
                  continue;
              processed[k] = 1;
              for( int m=0; m<adj[k].size(); ++m ) {
                  int d = dist[k] + cost[k][m];
                  if ( dist[adj[k][m]] > d )
                  {
                      dist[adj[k][m]] = d;
                  }
              }
          }
      }
      
      for(int k=0; k<adj.size(); ++k) {
          if (dist[k] == numeric_limits<int>::max())
              continue;
          for( int m=0; m<adj[k].size(); ++m ) {
              int d = dist[k] + cost[k][m];
              if( dist[adj[k][m]] > d)
              {
                  return 1;
              }
          }
      }
  }

  return 0;
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
  std::cout << negative_cycle(adj, cost);
}
