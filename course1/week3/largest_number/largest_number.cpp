#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

string array_to_string(const vector<string> &a) {
    std::stringstream ret;
    for(size_t i = 0; i < a.size(); i++) {
        ret << a[i];
    }
    return ret.str();
}

string largest_number_naive(vector<string> a) {
    std::sort(a.begin(), a.end());
    string max_str = array_to_string(a);
    while(std::next_permutation(a.begin(),a.end())) {
        string s = array_to_string(a);
        if (s > max_str)
            max_str = s;
    }
    return max_str;
}

bool compare(const string& s1, size_t st1, const string& s2, size_t st2) {
    while((st1 < s1.size()) && (st2 < s2.size())) {
        if(s1[st1] != s2[st2])
            return s1[st1] > s2[st2];
        st1++;
        st2++;
    }
    if(st1 < s1.size())
        return compare(s1,st1,s2,0);
    else if (st2 < s2.size())
        return compare(s1,0,s2,st2);
    return true;
}

string largest_number(vector<string> a) {
  //write your code here
  for(int i=0;i<a.size()-1;i++) {
      for(int j=i+1;j<a.size();j++) {
          if(!compare(a[i],0,a[j],0))
              std::swap(a[i],a[j]);
      }
  }
      
  std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;

  if(0) {
  while(true)
  {
    n = rand() % 8 + 2;
    vector<string> b;
    for(int i=0; i<n; i++) {
        b.push_back(std::to_string(rand() % 9999));
        std::cout << b.back() << " ";
    }
    std::cout << std::endl;
    string lnn = largest_number_naive(b);
    string ln = largest_number(b);
    if (lnn != ln) {
        std::cout << lnn << " != " << ln << std::endl;
        return -1;
    }
  }
  }

  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
