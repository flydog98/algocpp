// S4 2108 통계학

#include <iostream>
#include <cmath>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

typedef pair<int, int> p;

bool comp(p a, p b) {
  if(a.first == b.first) {
    return a.second < b.second;
  }
  return a.first > b.first;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, temp;
  vector<int> numbers;
  vector<p> mosts;

  cin >> N;

  for(int i = 0; i < N; i++) {
    cin >> temp;

    numbers.push_back(temp);
  }

  sort(numbers.begin(), numbers.end());

  // 산술평균
  cout << llround((double)accumulate(numbers.begin(), numbers.end(), 0) / N) << '\n';

  // 중앙값
  cout << *(numbers.begin() + (N / 2)) << '\n';

  // 최빈값
  int now = *numbers.begin();
  int count = 1;
  vector<int>::iterator beg = numbers.begin();
  for(int i = 1; i < N; i++) {
    if(now == *(beg + i)) {
      count++;
    }
    else {
      mosts.push_back(make_pair(count, now));
      count = 1;
      now = *(beg + i);
    }
  }
  mosts.push_back(make_pair(count, now));

  sort(mosts.begin(), mosts.end(), comp);

  if(mosts.size() > 1 && mosts[0].first == mosts[1].first) {
    cout << mosts[1].second << '\n';
  }
  else {
    cout << mosts[0].second << '\n';
  }

  // 범위
  cout << (*(numbers.end() - 1) - *numbers.begin()) << '\n';

  return 0;
}