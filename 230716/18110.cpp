// S4 18110 solved.ac

#include <iostream>
#include <cmath>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  int diff;
  int cut;
  vector<int> diffs;

  cin >> n;

  if(n == 0) {
    cout << 0 << '\n';
    return 0;
  }

  cut = round(n * 0.15);

  for(int i = 0; i < n; i++) {
    cin >> diff;
    diffs.push_back(diff);
  }

  sort(diffs.begin(), diffs.end());
  cout << round((double)accumulate(diffs.begin() + cut, diffs.end() - cut, 0) / (n - cut * 2)) << '\n';

  return 0;
}