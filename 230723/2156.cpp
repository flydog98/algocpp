// S1 2156 포도주 시식

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  int temp, temp2;

  cin >> N;

  if(N == 1) {
    cin >> temp;
    cout << temp << '\n';
    return 0;
  }
  if(N == 1) {
    cin >> temp >> temp2;
    cout << temp + temp2 << '\n';
    return 0;
  }

  vector<int> best00(2);
  vector<int> best01(2);
  vector<int> best10(2);
  vector<int> best11(2);

  cin >> temp >> temp2;
  best00.push_back(0);
  best01.push_back(temp2);
  best10.push_back(temp);
  best11.push_back(temp + temp2);

  for(int i = 3; i < N + 1; i++) {
    cin >> temp;
    best11.push_back(best01[i - 1] + temp);
    best01.push_back(max(best00[i - 1], best10[i - 1]) + temp);
    best10.push_back(max(best01[i - 1], best11[i - 1]));
    best00.push_back(max(best00[i - 1], best10[i - 1]));
  }

  cout << max(max(best00[N], best01[N]), max(best10[N], best11[N])) << '\n';

  return 0;
}