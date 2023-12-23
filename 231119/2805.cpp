// S2 2805 나무 자르기

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll N, M;
  vector<ll> tree;
  ll start = 1, end = 0;
  ll ans = 0;

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    ll temp;
    cin >> temp;
    end = max(end, temp);
    tree.push_back(temp);
  }

  while(start <= end) {
    ll mid = (start + end) / 2;

    ll cut = 0;

    for (int i = 0; i < N; i++) {
      if(tree[i] > mid) {
        cut += tree[i] - mid;
      }
    }

    if(cut >= M) {
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
