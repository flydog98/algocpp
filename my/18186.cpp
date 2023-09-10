// 18186 라면 사기(large)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll N, B, C, input;
  ll ans = 0;
  vector<ll> ramens;
  
  cin >> N >> B >> C;

  if (B < C) {
    for(int i = 0; i < N; i++) {
      cin >> input;
      ans += input * B;
    }
    cout << ans << '\n';
    return 0;
  }

  for(int i = 0; i < N; i++) {
    cin >> input;
    ramens.push_back(input);
  }

  for(int i = 0; i < N; i++) {
    if(i == N - 1) {
      ll now = ramens[i];
      ans += now * B;
    }
    else if (i == N - 2) {
      ll now = ramens[i];
      ll now1 = ramens[i + 1];
      ll count = min(now, now1);

      ans += (B + C) * count;
      now -= count;
      now1 -= count;
      
      ans += B * now;
      
      ramens[i + 1] = now1;
    }
    else {
      ll now = ramens[i];
      ll now1 = ramens[i + 1];
      ll now2 = ramens[i + 2];

      if (now1 > now2) {
        ll count = min(now, now1 - now2);
        ans += (B + C) * count;
        now -= count; now1 -= count;
      }
      if(now > 0 && now1 > 0 && now2 > 0) {
        ll count = min(now, min(now1, now2));
        ans += (B + C + C) * count;
        now -= count; now1 -= count; now2 -= count;
      }
      if(now > 0) {
        ans += B * now;
      }
      ramens[i + 1] = now1;
      ramens[i + 2] = now2;
    }
  }

  cout << ans << '\n';

  return 0;
}