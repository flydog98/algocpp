// S1 2667 단지번호붙이기

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> p;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  string input;
  vector<int> amount;

  cin >> N;

  vector<vector<int> > board(N, vector <int>(N,0));
  vector<vector<int> > visit(N, vector <int>(N,0));
  queue<p> q;

  for(int i = 0; i < N; i++) {
    cin >> input;
    for(int j = 0; j < N; j++) {
      board[i][j] = (int)(input[j] - '0');
    }
  }

  for(int y = 0; y < N; y++) {
    for(int x = 0; x < N; x++) {
      if(board[y][x] == 1 && !visit[y][x]) {
        int count = 0;
        q.push(make_pair(y, x));
        visit[y][x] = 1;

        while(!q.empty()) {
          int nowy = q.front().first, nowx = q.front().second;
          q.pop();
          count++;

          for(int i = 0; i < 4; i++) {
            int nexty = nowy + dy[i];
            int nextx = nowx + dx[i];

            if((0 <= nexty && nexty < N)
              && (0 <= nextx && nextx < N)
              && board[nexty][nextx] == 1
              && !visit[nexty][nextx]) {
              visit[nexty][nextx] = 1;
              q.push(make_pair(nexty, nextx));
            }
          }
        }

        amount.push_back(count);
      }
    }
  }

  sort(amount.begin(), amount.end());

  cout << amount.size() << '\n';

  for(int count : amount) {
    cout << count << '\n';
  }

  return 0;
}