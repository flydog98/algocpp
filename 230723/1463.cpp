// S3 1463 1로 만들기

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<int> ans;

  ans.push_back(0);
  ans.push_back(0);
  ans.push_back(1);
  ans.push_back(1);

  for(int i = 4; i < 1000001; i++) {
    int temp = ans[i - 1];
    if(i % 2 == 0) {
      temp = min(temp, ans[i / 2]);
    }
    if(i % 3 == 0) {
      temp = min(temp, ans[i / 3]);
    }
    ans.push_back(temp + 1);
  }

  int N;

  cin >> N;
  cout << ans[N] << '\n';
  
  return 0;
}