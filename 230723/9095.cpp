// S3 9095 1, 2, 3 더하기

#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<int> ans;

  ans.push_back(0);
  ans.push_back(1);
  ans.push_back(2);
  ans.push_back(4);

  for(int i = 4; i < 12; i++) {
    ans.push_back(ans[i - 1] + ans[i - 2] + ans[i - 3]);
  }

  int T, N;

  cin >> T;
  while(T--){
    cin >> N;
    cout << ans[N] << '\n';
  }
  
  return 0;
}