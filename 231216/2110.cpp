// 2110번 공유기 설치

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, C;
  vector<int> point;
  int answer = 0;

  cin >> N >> C;

  for(int i = 0; i < N; i++) {
    int temp;
    cin >> temp;
    point.push_back(temp);
  }

  sort(point.begin(), point.end());

  int start = 1, end = 1000000000;

  while(start <= end) {
    int mid = (end + start) / 2;
    int count = 1;
    int set = point[0];

    for(int i = 1; i < N; i++) {
      if(point[i] - set >= mid) {
        set = point[i];
        count += 1;
      }
    }

    if(count >= C) {
      answer = max(answer, mid);
      start = mid + 1;
    }
    else {
      end = mid - 1;
    }
  }

  cout << answer << '\n';

  return 0;
}
