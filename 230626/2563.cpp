// S5 2363 색종이

#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  int a, b;
  int ans = 0;
  vector<vector<int> > board(100, vector<int>(100, 0));

  cin >> N;

  for(int i = 0; i < N; i++) {
    cin >> a >> b;
    for(int j = a; j < a + 10; j++) {
      for(int k = b; k < b + 10; k++) {
        board[j][k] = 1;
      }
    }
  }

  for(int i = 0; i < 100; i++) {
    for(int j = 0; j < 100; j++) {
      if(board[i][j]) ans++;
    }
  }

  cout << ans << '\n';

  return 0;
}