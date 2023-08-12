// S3 11726 2xn 타일링

#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<int> ans;

  ans.push_back(1);
  ans.push_back(1);
  ans.push_back(2);

  for(int i = 3; i < 1001; i++) {
    ans.push_back((ans[i - 1] + ans[i - 2]) % 10007);
  }

  int N;

  cin >> N;

  cout << ans[N] << '\n';

  return 0;
}