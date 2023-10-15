// 1149 RGB거리

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

  vector<vector<int> > house(N, vector<int>(3, 0));
  vector<vector<int> > value(N, vector<int>(3, 0));

  for(int i = 0; i < N; i++) {
    cin >> house[i][0] >> house[i][1] >> house[i][2];
  }

  value[0][0] = house[0][0];
  value[0][1] = house[0][1];
  value[0][2] = house[0][2];

  for(int i = 1; i < N; i++) {
    value[i][0] = house[i][0] + min(value[i - 1][1], value[i - 1][2]);
    value[i][1] = house[i][1] + min(value[i - 1][0], value[i - 1][2]);
    value[i][2] = house[i][2] + min(value[i - 1][0], value[i - 1][1]);
  }

  cout << min(value[N - 1][0], min(value[N - 1][1], value[N - 1][2])) << '\n';

  return 0;
}