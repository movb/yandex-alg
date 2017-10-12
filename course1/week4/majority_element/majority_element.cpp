#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  int majority = a[0];
  int count = 1;

  for(int i=1;i<a.size();++i) {
      if(a[i] == majority)
          count++;
      else
          count--;
      if (count == 0) {
          majority = a[i];
          count = 1;
      }
  }
  
  count = 0;
  for(int i=0;i<a.size();++i)
      if (a[i] == majority)
          count++;

  if (count > a.size()/2)
      return majority;
  
  //write your code here
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
