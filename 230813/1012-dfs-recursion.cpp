// S2 1012 유기농 배추

#include <iostream>
#include <vector>

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int M, N, K;
vector<vector<int> > board(51, vector <int>(51,0));
vector<vector<int> > myvisit(51, vector <int>(51,0));

void dfs(int y, int x) {
  myvisit[y][x] = 1;

  for(int i = 0; i < 4; i++) {
    int nexty = y + dy[i];
    int nextx = x + dx[i];

    if((0 <= nexty && nexty < N)
      && (0 <= nextx && nextx < M)
      && board[nexty][nextx] == 1
      && !myvisit[nexty][nextx]) {
      dfs(nexty, nextx);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;

  cin >> T;

  while(T--) {
    int y, x;
    int answer = 0;

    cin >> M >> N >> K;

    for(int i = 0; i < K; i++) {
      cin >> x >> y;
      board[y][x] = 1;
    }

    for(int y = 0; y < N; y++) {
      for(int x = 0; x < M; x++) {
        if(board[y][x] == 1 && !myvisit[y][x]) {
          dfs(y, x);
          answer++;
        }
      }
    }

    for(int i = 0; i < N; i++) {
      for(int j = 0; j < M; j++) {
        board[i][j] = 0;
        myvisit[i][j] = 0;
      }
    }

    cout << answer << '\n';
  }

  return 0;
}