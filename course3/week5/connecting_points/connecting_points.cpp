#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <queue>
#include <limits>
#include <numeric>

using std::vector;
using std::priority_queue;
using std::pair;
using std::numeric_limits;
using std::greater;

double dist(int x1, int y1, int x2, int y2) {
    return sqrt( pow(x1-x2, 2) + pow(y1-y2, 2));
}

double minimum_distance(vector<int> x, vector<int> y) {
  double result = 0.;
  //write your code here
  priority_queue<pair<double, int>, vector<pair<double,int>>, greater<pair<double,int>>> q;

  vector<int> discovered(x.size(), 0);
  vector<double> cost(x.size(), numeric_limits<double>::max());

  q.emplace(0, 0);

  while(!q.empty()) {
      auto v = q.top();
      q.pop();
      //std::cout << "Found " << v.second << " (" << v.first << ")" << std::endl;
      if (discovered[v.second])
         continue;
      discovered[v.second] = 1;
      cost[v.second] = v.first;

      for(int i=0; i<x.size(); ++i) {
          if (discovered[i])
              continue;

          q.emplace(dist(x[v.second], y[v.second], x[i], y[i]), i);
      }
  }

  result = std::accumulate(cost.begin(), cost.end(), 0.0);

  return result;
} 

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}
