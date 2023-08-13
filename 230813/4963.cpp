// S2 4963 섬의 개수

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> p;

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  int w, h;
  int temp;

  while(true) {
    cin >> w >> h;

    if(!w || !h) break;

    int answer = 0;

    vector<vector<int> > board(h, vector <int>(w,0));
    vector<vector<int> > visit(h, vector <int>(w,0));
    queue<p> q;

    for(int y = 0; y < h; y++) {
      for(int x = 0; x < w; x++) {
        cin >> temp;
        board[y][x] = temp;
      }
    }

    for(int y = 0; y < h; y++) {
      for(int x = 0; x < w; x++) {
        if(board[y][x] == 1 && visit[y][x] == 0) {
          q.push(make_pair(y, x));
          visit[y][x] = 1;

          while(!q.empty()) {
            int nowy = q.front().first;
            int nowx = q.front().second;
            q.pop();

            for(int i = 0; i < 8; i++) {
              int nexty = nowy + dy[i];
              int nextx = nowx + dx[i];

              if((0 <= nexty && nexty < h)
                && (0 <= nextx && nextx < w)
                && board[nexty][nextx] == 1
                && visit[nexty][nextx] == 0) {
                visit[nexty][nextx] = 1;
                q.push(make_pair(nexty, nextx));
              }
            }
          }
          answer++;
        }
      }
    }

    cout << answer << '\n';
  }

  return 0;
}