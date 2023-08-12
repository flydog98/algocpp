// S3 1003 피보나치 함수

#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> p;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T, N;
  vector<p> fibonacci;

  fibonacci.push_back(make_pair(1, 0));
  fibonacci.push_back(make_pair(0, 1));

  for(int i = 2; i <= 40; i++) {
    fibonacci.push_back(make_pair(fibonacci[i - 1].first + fibonacci[i - 2].first, fibonacci[i - 1].second + fibonacci[i - 2].second));
  }

  cin >> T;

  while(T--) {
    cin >> N;

    cout << fibonacci[N].first << ' ' << fibonacci[N].second << '\n';
  }

  return 0;
}