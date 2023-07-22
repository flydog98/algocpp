// S4 11399 ATM

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  int temp;
  int answer = 0;
  vector<int> times;
  vector<int>::iterator iter;

  cin >> N;

  for(int i = 0; i < N; i++) {
    cin >> temp;
    times.push_back(temp);
  }

  sort(times.begin(), times.end());

  temp = 0;
  for(iter = times.begin(); iter < times.end(); iter++) {
    temp += *iter;
    answer += temp;
  }

  cout << answer << '\n';
  
  return 0;
}
