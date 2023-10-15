// 1932 정수 삼각형

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;

  cin >> N;

  vector<vector<int> > triangle(N, vector<int>(N, 0));
  vector<vector<int> > value(N, vector<int>(N, 0));

  for(int i = 0; i < N; i++) {
    for(int j = 0; j <= i; j++) {
      cin >> triangle[i][j];
    }
  }

  value[0][0] = triangle[0][0];

  for(int i = 1; i < N; i++) {
    value[i][0] = triangle[i][0] + value[i - 1][0];
    for(int j = 1; j < i; j++) {
      value[i][j] = triangle[i][j] + max(value[i - 1][j - 1], value[i - 1][j]);
    }
    value[i][i] = triangle[i][i] + value[i - 1][i - 1];
  }

  int ans = value[N - 1][0];

  for(int i = 1; i < N; i++) {
    ans = max(ans, value[N - 1][i]);
  }

  cout << ans << '\n';

  return 0;
}
