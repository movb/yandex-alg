#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }

  int size() {
      return data_.size();
  }

  int parent(int i) {
      return i/2;
  }

  int left(int i) {
      return 2*i+1;
  }

  int right(int i) {
      return 2*i+2;
  }

  bool compare(int first, int second) {
      // min heap
      return first > second;
  }

  void swap(int first, int second) {
      swaps_.emplace_back(first, second);
      std::swap(data_[first], data_[second]);
  }

  void siftUp(int i) {
      while( i > 0 && compare(data_[parent(i)], data_[i]) ) {
          swap(parent(i), i);
          i = parent(i);
      }
  }

  void siftDown(int i) {
      int maxIndex = i;

      int l = left(i);
      int r = right(i);

      if (l < size() && compare(data_[maxIndex], data_[l]))
          maxIndex = l;

      if (r < size() && compare(data_[maxIndex], data_[r]))
          maxIndex = r;

      if (i != maxIndex) {
          swap(i, maxIndex);
          siftDown(maxIndex);
      }
  }

  void GenerateSwaps() {
    swaps_.clear();

    for(int i=size()-1; i>=0; i--) {
        siftDown(i);
    }
  }

 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
