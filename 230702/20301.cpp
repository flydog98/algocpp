// S3 20301 반전 요세푸스

#include <iostream>
#include <deque>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, K, M;
  int count = 0;
  bool reverse = false;
  deque<int> input;
  queue<int> output;

  cin >> N >> K >> M;

  for(int i = 0; i < N; i++) {
    input.push_back(i + 1);
  }

  while(!input.empty()) {
    if(reverse) {
      for(int i = 0; i < K - 1; i++) {
        input.push_front(input.back());
        input.pop_back();
      }
      output.push(input.back());
      input.pop_back();
    }
    else {
      for(int i = 0; i < K - 1; i++) {
        input.push_back(input.front());
        input.pop_front();
      }
      output.push(input.front());
      input.pop_front();
    }
    count++;
    if(count == M) {
      count = 0;
      reverse = !reverse;
    }
  }

  for(int i = 0; i < N; i++) {
    cout << output.front() << '\n';
    output.pop();
  }
  
  return 0;
}