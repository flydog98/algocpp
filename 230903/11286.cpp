// 11286 절댓값 힙

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> p;

void swap(vector<p>& heap, int x, int y) {
  p temp = heap[x];
  heap[x] = heap[y];
  heap[y] = temp;
}

void push(vector<p>& heap, p x) {
  heap.push_back(x);

  int child = heap.size() - 1;
  int parent = child / 2;

  while(child > 1 && heap[child] < heap[parent]) {
    swap(heap, child, parent);
    child = parent;
    parent = child / 2;
  }
}

int pop(vector<p>& heap) {
  p ret = heap[1];
  int heapSize = heap.size() - 1;

  swap(heap, 1, heapSize);
  heap.pop_back();
  heapSize--;

  int parent = 1;
  int child = parent * 2;

  if(child + 1 <= heapSize) {
    child = (heap[child] < heap[child + 1]) ? child : child + 1;
  }

  while(child <= heapSize && heap[child] < heap[parent]) {
    swap(heap, child, parent);
    parent = child;
    child = parent * 2;

    if(child + 1 <= heapSize) {
      child = (heap[child] < heap[child + 1]) ? child : child + 1;
    }
  }

  return ret.second;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, input;
  vector<p> heap;

  heap.push_back(make_pair(0, 0));

  cin >> N;

  while(N--) {
    cin >> input;

    if(input) {
      push(heap, make_pair(abs(input), input));
    }
    else {
      if(heap.size() == 1) {
        cout << 0 << '\n';
      }
      else {
        cout << pop(heap) << '\n';
      }
    }
  }
  
  return 0;
}