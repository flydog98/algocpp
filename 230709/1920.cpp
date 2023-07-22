// S4 1920 수 찾기

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int search(vector<int>& numbers, int find) {
  int start = 0, end = numbers.size() - 1;
  int mid;

  while(start <= end) {
    mid = (start + end) / 2;
    if(numbers.at(mid) == find)
      return 1;
    else if(find < numbers.at(mid))
      end = mid - 1;
    else
      start = mid + 1;
  }

  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M;
  int temp, find;
  vector<int> numbers;

  cin >> N;

  for(int i = 0; i < N; i++) {
    cin >> temp;
    numbers.push_back(temp);
  }

  sort(numbers.begin(), numbers.end());

  cin >> M;

  for(int i = 0; i < M; i++) {
    cin >> find;
    cout << search(numbers, find) << '\n';
  }
  
  return 0;
}
