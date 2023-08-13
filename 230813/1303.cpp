// S1 1303 전쟁 - 전투

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> p;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M;
  string temp;
  int w = 0, b = 0;

  cin >> N >> M;

  vector<vector<char> > board(M, vector <char>(N,' '));
  vector<vector<int> > visit(M, vector <int>(N,0));
  queue<p> q;

  for(int y = 0; y < M; y++) {
    cin >> temp;
    for(int x = 0; x < N; x++) {
      board[y][x] = temp[x];
    }
  }

  for(int y = 0; y < M; y++) {
    for(int x = 0; x < N; x++) {
      if(visit[y][x] == 0) {
        char nowcolor = board[y][x];
        int amount = 0;
        q.push(make_pair(y, x));
        visit[y][x] = 1;

        while(!q.empty()) {
          int nowy = q.front().first;
          int nowx = q.front().second;
          q.pop();
          amount ++;

          for(int i = 0; i < 4; i++) {
            int nexty = nowy + dy[i];
            int nextx = nowx + dx[i];

            if((0 <= nexty && nexty < M)
              && (0 <= nextx && nextx < N)
              && board[nexty][nextx] == nowcolor
              && visit[nexty][nextx] == 0) {
              visit[nexty][nextx] = 1;
              q.push(make_pair(nexty, nextx));
            }
          }
        }
        if(nowcolor == 'W') {
          w += amount * amount;
        }
        else {
          b += amount * amount;
        }
      }
    }
  }

  cout << w << ' ' << b << '\n';
  
  return 0;
}