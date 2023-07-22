// S4 1158 요세푸스 문제

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, K;
  queue<int> input;
  queue<int> output;

  cin >> N >> K;

  for(int i = 0; i < N; i++) {
    input.push(i + 1);
  }

  while(!input.empty()) {
    for(int i = 0; i < K - 1; i++) {
      input.push(input.front());
      input.pop();
    }
    output.push(input.front());
    input.pop();
  }

  cout << '<';
  for(int i = 0; i < N - 1; i++) {
    cout << output.front() << ", ";
    output.pop();
  }
  cout << output.front() << ">\n";

  return 0;
}