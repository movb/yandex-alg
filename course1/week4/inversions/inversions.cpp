#include <iostream>
#include <vector>

using std::vector;

long long get_number_of_inversions(vector<long> &a, vector<long> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left + 1) return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave, right);

  size_t i=left, j=ave, k=left;
  while(i<ave && j<right) {
      if (a[i]<=a[j]) {
          b[k++] = a[i++];
      }
      else {
          b[k++] = a[j++];
          number_of_inversions += (ave - i);
      }
  }
  while(i<ave) b[k++] = a[i++];
  while(j<right) b[k++] = a[j++];
  std::copy(b.begin()+left, b.begin()+right, a.begin()+left);

  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<long> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<long> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
}
