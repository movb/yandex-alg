#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;

template<typename T>
class PriorityQueue {
    vector<T> storage;
public:
    bool empty() {
        return storage.empty();
    }
    template< class InputIt >
    void assign(InputIt first, InputIt last) {
        storage.assign(first, last);
        build();
    }
    long long parent(long long i) { return (i-1)/2; }
    long long left(long long i) { return i*2+1; }
    long long right(long long i) { return i*2+2; } 
    bool compare(long long first,long long last) {
        return !(storage[first] < storage[last]);
    }
    void swap(long long first, long long last) {
        std::swap(storage[first], storage[last]);
    }
    long long size() {
        return storage.size();
    }
    void siftUp(long long i) {
        while(i>0 && compare(parent(i), i)) {
            swap(parent(i), i);
            i = parent(i);
        }
    }
    void siftDown(long long i) {
        long long maxIndex = i;
        long long l = left(i);
        long long r = right(i);

        if (l < size() && compare(maxIndex, l)) 
            maxIndex = l;
        if (r < size() && compare(maxIndex, r))
            maxIndex = r;

        if (i != maxIndex) {
            swap(i, maxIndex);
            siftDown(maxIndex);
        }
    }
    void build() {
        for(int i=size()-1; i>=0; i--)
            siftDown(i);
    }
    void push(const T& elem) {
        storage.push_back(elem);
        siftUp(size()-1);
    }
    T& getTop() {
        return storage.front();
    }
    T extractTop() {
        T top=storage.front();
        if (size() > 1) {
            storage[0] = storage[size()-1];
            storage.pop_back();
            siftDown(0);
        } else {
            storage.pop_back();
        }
        return top;
    }
    void changePriority(long long i, long long p) {
        long long oldp = storage[i];
        storage[i] = p;
        if( compare(oldp, p) ) {
            siftUp(i);
        } else {
            siftDown(i);
        }
    }
};

struct Worker {
    long long index;
    long long end_time;

    Worker(long long index, long long end_time):
        index(index),
        end_time(end_time)
    {}

    bool operator<(const Worker& rhs) const {
        if (end_time != rhs.end_time)
            return end_time < rhs.end_time;
        return index < rhs.index;
    } 
};


class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;

  vector<int> assigned_workers_;
  vector<long long> start_times_;

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }

  void AssignJobs() {
      PriorityQueue<Worker> queue;
      for(int i = 0; i< num_workers_; ++i) {
          queue.push(Worker(i,0));
      }
      
      vector<long long> next_free_time(num_workers_, 0);
    for (int i = 0; i < jobs_.size(); ++i) {
        int duration = jobs_[i];
        
        auto top = queue.extractTop();
        assigned_workers_.push_back(top.index);
        start_times_.push_back(top.end_time);

        top.end_time += duration;

        queue.push(top);
    }
  }  

public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
