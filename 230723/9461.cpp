// S3 9461 파도반 수열

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<ll> ans;

  ans.push_back(0);
  ans.push_back(1);
  ans.push_back(1);
  ans.push_back(1);
  ans.push_back(2);
  ans.push_back(2);

  for(int i = 6; i < 101; i++) {
    ans.push_back(ans[i - 1] + ans[i - 5]);
  }

  int T, N;

  cin >> T;
  while(T--) {
    cin >> N;
    cout << ans[N] << '\n';
  }
  return 0;
}