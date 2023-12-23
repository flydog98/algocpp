// 13702 이상한 술집

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, K;
  vector<int> kettle;
  ll start = 0, end = 3000000000;
  ll ans = 0;

  cin >> N >> K;

  for (int i = 0; i < N; i++) {
    int temp;
    cin >> temp;
    kettle.push_back(temp);
  }

  while(start <= end) {
    ll mid = (end + start) / 2;
    ll count = 0;

    for(int i = 0; i < N; i++) {
      count += kettle[i] / mid;
    }

    if(count >= K) {
      ans = max(mid, ans);
      start = mid + 1;
    }
    else {
      end = mid - 1;
    }
  }
  
  cout << ans << '\n';

  return 0;
}
