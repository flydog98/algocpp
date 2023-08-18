// S4 14244 트리 만들기

#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;

  cin >> n >> m;

  for(int i = 1; i < n; i++) {
    if (i <= m) {
      cout << 0 << ' ' << i << '\n';
    }
    else {
      cout << i - 1 << ' ' << i << '\n';
    }
  }

  return 0;
}