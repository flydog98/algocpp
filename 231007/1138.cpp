// 1138 한 줄로 서기

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, temp, at, count;

  cin >> N;

  vector<int> result(N, 0);

  for(int i = 0; i < N; i++) {
    cin >> temp;

    at = 0, count = 0;
    while(count < temp || result[at]) {
      if(!result[at]) count++;
      at++;
    }
    result[at] = i + 1;
  }

  for(int i = 0; i < N; i++) {
    cout << result[i] << ' ';
  }
  cout << '\n';

  return 0;
}