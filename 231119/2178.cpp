// S1 2178 미로 탐색

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> p;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M;
  queue<p> q;

  cin >> N >> M;

  vector<vector<int> > maze(N, vector<int>(M, 0));
  vector<vector<int> > visit(N, vector<int>(M, -1));

  for(int i = 0; i < N; i++) {
    string line;

    cin >> line;

    for(int j = 0; j < M; j++) {
      maze[i][j] = int(line[j] - '0');
    }
  }

  q.push(make_pair(0, 0));
  visit[0][0] = 1;

  while(!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    int now = visit[y][x];
    q.pop();

    if(y == N - 1 && x == M - 1) {
      cout << now << '\n';
      break;
    }

    for(int i = 0; i < 4; i++) {
      int goy = y + dy[i];
      int gox = x + dx[i];

      if(0 <= goy && goy < N && 0 <= gox && gox < M && maze[goy][gox] == 1 && visit[goy][gox] == -1) {
        q.push(make_pair(goy, gox));
        visit[goy][gox] = now + 1;
      }
    }
  }
  
  return 0;
}