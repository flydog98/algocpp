// 6236번 용돈 관리

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

  vector<int> money;
  int answer = 1000000000;

  cin >> N >> M;

  for(int i = 0; i < N; i++) {
    int temp;
    cin >> temp;
    money.push_back(temp);
  }

  int start = *max_element(money.begin(), money.end()), end = 1000000000;

  while(start <= end) {
    int mid = (end + start) / 2;
    int draw = 0;
    int nowmoney = 0;

    for(int i = 0; i < N; i++) {
      if(nowmoney < money[i]) {
        draw += 1;
        nowmoney = mid;
      }
      nowmoney -= money[i];
    }

    if(draw > M) {
      start = mid + 1;
    }
    else {
      end = mid - 1;
      answer = min(mid, answer);
    }
  }

  cout << answer << '\n';

  return 0;
}
