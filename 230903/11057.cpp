// 11057 오르막 수

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll DIV = 10007;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;

  cin >> N;

  vector<vector<ll> > upper(10, vector<ll>(1, 0));

  for(int i = 0; i <= 9; i++) {
    upper[i].push_back(1);
  }

  for(int i = 2; i <= 1000; i++) {
    upper[0].push_back(upper[0][i - 1]);

    for(int j = 1; j <= 9; j++) {
      ll temp = 0;
      for(int k = 0; k <= j; k++) {
        temp += upper[k][i - 1];
        temp %= DIV;
      }
      upper[j].push_back(temp);
    }
  }

  ll ans = 0;

  for(int i = 0; i <= 9; i++) {
    ans += upper[i][N];
    ans %= DIV;
  }

  cout << ans << '\n';

  return 0;
}