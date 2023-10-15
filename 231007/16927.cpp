// 16927 배열 돌리기 2

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int N, M;

void calcCount(vector<vector<int> >& board, int depth, int amount) {
  int x = depth;
  int y = depth;
  int X = M - depth;
  int Y = N - depth;
  
  while(amount--) {
    int a = board[y][x];

    for(int j = x; j < X - 1; j++) {
      board[y][j] = board[y][j + 1];
    }

    for(int i = y; i < Y - 1; i++) {
      board[i][X - 1] = board[i + 1][X - 1];
    }

    for(int j = X - 1; j > x; j--) {
      board[Y - 1][j] = board[Y - 1][j - 1];
    }

    for(int i = Y - 1; i > y; i--) {
      board[i][x] = board[i - 1][x];
    }
    
    board[y + 1][x] = a;

    // for(int i = 0; i < N; i++) {
    //   for(int j = 0; j < M; j++) {
    //     cout << board[i][j] << ' ';
    //   }
    //   cout << '\n';
    // }
    // cout << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll R, move;

  cin >> N >> M >> R;

  vector<vector<int> > board(N, vector<int>(M, 0));

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      cin >> board[i][j];
    }
  }

  int hor = M - 1;
  int ver = N - 1;

  for(int depth = 0; depth < min(N, M) / 2; depth++) {
    calcCount(board, depth, R % (hor * 2 + ver * 2));
    hor -= 2;
    ver -= 2;

  }

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      cout << board[i][j] << ' ';
    }
    cout << '\n';
  }

  return 0;
}
