// S5 11650 좌표 정렬하기

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> p;

bool compare(p a, p b) {
  if(a.first != b.first) {
    return a.first < b.first;
  }
  else {
    return a.second < b.second;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  int x, y;
  vector<p> v;
  vector<p>::iterator iter;

  cin >> N;

  for(int i = 0; i < N; i++) {
    cin >> x >> y;
    v.push_back(make_pair(x, y));
  }

  sort(v.begin(), v.end(), compare);

  for(iter = v.begin(); iter < v.end(); iter++) {
    p now = *iter;
    cout << now.first << ' ' << now.second << '\n';
  }

  return 0;
}