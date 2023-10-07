// 13335 트럭

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, w, l, temp, sum = 0, ans = 0, at = 0;
  vector<int> trucks;
  queue<int> q;

  cin >> n >> w >> l;

  for(int i = 0; i < n; i++) {
    cin >> temp;
    trucks.push_back(temp);
  }

  while(true) {
    ans++;
    if(q.size() == w) {
      temp = q.front();
      sum -= temp;
      q.pop();
      if(at == n && sum == 0) break;
    }

    if(at < n && sum + trucks[at] <= l) {
      q.push(trucks[at]);
      sum += trucks[at];
      at++;
    }
    else {
      q.push(0);
    }
  }

  cout << ans << '\n';

  return 0;
}