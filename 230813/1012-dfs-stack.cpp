// S2 1012 유기농 배추

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef pair<int, int> p;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;

  vector<vector<int> > board(51, vector <int>(51,0));
  vector<vector<int> > visit(51, vector <int>(51,0));
  stack<p> s;

  cin >> T;

  while(T--) {
    int M, N, K;
    int y, x;
    int answer = 0;

    cin >> M >> N >> K;

    for(int i = 0; i < K; i++) {
      cin >> x >> y;
      board[y][x] = 1;
    }

    for(int y = 0; y < N; y++) {
      for(int x = 0; x < M; x++) {
        if(board[y][x] == 1 && !visit[y][x]) {
          s.push(make_pair(y, x));
          visit[y][x] = 1;

          while(!s.empty()) {
            int nowy = s.top().first, nowx = s.top().second;
            s.pop();

            for(int i = 0; i < 4; i++) {
              int nexty = nowy + dy[i];
              int nextx = nowx + dx[i];

              if((0 <= nexty && nexty < N)
                && (0 <= nextx && nextx < M)
                && board[nexty][nextx] == 1
                && !visit[nexty][nextx]) {
                visit[nexty][nextx] = 1;
                s.push(make_pair(nexty, nextx));
              }
            }
          }

          answer++;
        }
      }
    }

    for(int i = 0; i < N; i++) {
      for(int j = 0; j < M; j++) {
        board[i][j] = 0;
        visit[i][j] = 0;
      }
    }

    cout << answer << '\n';
  }

  return 0;
}