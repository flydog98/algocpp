// S2 1654 랜선 자르기

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll K, N;
  vector<ll> lans;
  ll start = 1, end = 0;
  ll ans = 0;

  cin >> K >> N;

  for (int i = 0; i < K; i++) {
    ll temp;
    cin >> temp;
    end = max(end, temp);
    lans.push_back(temp);
  }

  while(start <= end) {
    ll mid = (start + end) / 2;

    ll made = 0;

    for (int i = 0; i < K; i++) {
      made += lans[i] / mid;
    }

    if(made >= N) {
      start = mid + 1;
      ans = max(ans, mid);
    }
    else {
      end = mid - 1;
    }
  }

  cout << ans << '\n';

  return 0;
}
