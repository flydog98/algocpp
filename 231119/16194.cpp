// S1 16194 카드 구매하기 2

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  vector<int> value;
  vector<int> dp;

  cin >> N;

  for(int i = 0; i < N; i++) {
    int temp;
    cin >> temp;
    value.push_back(temp);
  }

  for(int i = 0; i < N; i++) {
    int min_value = value[i];
    for(int j = 0; j < i; j++) {
      min_value = min(min_value, dp[j] + value[i - 1 - j]);
    }
    dp.push_back(min_value);
  }

  cout << dp[N - 1] << '\n';
  
  return 0;
}