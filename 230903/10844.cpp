// 10844 쉬운 계단 수

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll DIV = 1000000000;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;

  cin >> N;

  vector<vector<ll> > stair(10, vector<ll>(1, 0));

  stair[0].push_back(0);
  for(int i = 1; i <= 9; i++) {
    stair[i].push_back(1);
  }

  for(int i = 2; i <= 100; i++) {
    stair[0].push_back(stair[1][i - 1]);

    for(int j = 1; j < 9; j++) {
      stair[j].push_back((stair[j - 1][i - 1] + stair[j + 1][i - 1]) % DIV);
    }

    stair[9].push_back(stair[8][i - 1]);
  }

  ll ans = 0;

  for(int i = 0; i <= 9; i++) {
    ans += stair[i][N];
    ans %= DIV;
  }

  cout << ans << '\n';

  return 0;
}