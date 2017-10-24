#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using std::pair;

void dfs(vector<vector<int> >& adj, vector<int>& used, vector<int>& order, int x) 
{
    used[x] = true;
    for(int i=0; i< adj[x].size(); ++i) {
        if(used[adj[x][i]])
            continue;
        dfs(adj, used, order, adj[x][i]);
    }
    order.push_back(x);
}

void explore(vector<vector<int> >& adj, vector<int>& used, int x) {
    used[x] = 1;
    for(int j=0; j<adj[x].size(); ++j)
    {
        if(!used[adj[x][j]])
            explore(adj,used,adj[x][j]);
    }
}
            


int number_of_strongly_connected_components(vector<vector<int> > adj) {
  int result = 0;
  vector<int> used(adj.size(), 0);
  vector<int> order;
  
  vector<vector<int> > adj_r(adj.size(), vector<int>());
  for(int i=0; i<adj.size(); ++i) 
      for(int j=0; j<adj[i].size(); ++j)
          adj_r[adj[i][j]].push_back(i);

  for(int i=0; i<adj_r.size(); ++i) {
      if(!used[i])
          dfs(adj_r, used, order, i);
  }
  
  used = vector<int>(adj.size(), 0);
  for(int i=order.size()-1; i>=0; --i) 
  {
      if(used[order[i]])
          continue;
      result+=1;
      explore(adj, used, order[i]);
  }
  
  //write your code here
  return result;
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
  std::cout << number_of_strongly_connected_components(adj);
}
