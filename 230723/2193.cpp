// S3 2193 이친수

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

  for(int i = 3; i < 91; i++) {
    ans.push_back(ans[i - 1] + ans[i - 2]);
  }

  int N;

  cin >> N;
  cout << ans[N] << '\n';
  
  return 0;
}