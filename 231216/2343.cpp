// 2343 기타 레슨

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M;
  vector<int> length;
  ll answer = 1000000001;

  cin >> N >> M;

  for(int i = 0; i < N; i++) {
    int temp;
    cin >> temp;
    length.push_back(temp);
  }

  ll start = *max_element(length.begin(), length.end()), end = 1000000000;

  while(start <= end) {
    ll mid = (end + start) / 2;
    int stored = 0;
    int count = 1;

    for(int i = 0; i < N; i++) {
      int now = length[i];
      if(stored + now > mid) {
        count += 1;
        stored = now;
      }
      else {
        stored += now;
      }
    }

    if(count <= M) {
      end = mid - 1;
      answer = min(answer, mid);
    }
    else {
      start = mid + 1;
    }
  }

  cout << answer << '\n';

  return 0;
}
