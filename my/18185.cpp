// 18185 라면 사기(small)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, input;
  ll ans = 0;
  vector<int> ramens;
  
  cin >> N;

  for(int i = 0; i < N; i++) {
    cin >> input;
    ramens.push_back(input);
  }

  for(int i = 0; i < N; i++) {
    if(i == N - 1) {
      int now = ramens[i];
      while(now > 0) {
        now--;
        ans += 3;
      }
    }
    else if (i == N - 2) {
      int now = ramens[i];
      int now1 = ramens[i + 1];

      while(now > 0 && now1 > 0) {
        now--;now1--;
        ans += 5;
      }
      while(now > 0) {
        now--;
        ans += 3;
      }
      ramens[i + 1] = now1;
    }
    else {
      int now = ramens[i];
      int now1 = ramens[i + 1];
      int now2 = ramens[i + 2];

      while (now1 > now2 && now > 0 && now1 > 0) {
        now--;now1--;
        ans += 5;
      }
      while(now > 0 && now1 > 0 && now2 > 0) {
        now--;now1--;now2--;
        ans += 7;
      }
      while(now > 0) {
        now--;
        ans += 3;
      }
      ramens[i + 1] = now1;
      ramens[i + 2] = now2;
    }
  }

  cout << ans << '\n';

  return 0;
}