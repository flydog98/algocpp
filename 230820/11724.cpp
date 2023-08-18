// S2 11724 연결 요소의 개수

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M, u, v;
  int answer = 0;

  cin >> N >> M;

  vector<vector<int> > link(N + 1, vector <int>());
  vector<int> visit(N + 1, 0);

  for(int i = 0; i < M; i++) {
    cin >> u >> v;
    link[u].push_back(v);
    link[v].push_back(u);
  }

  for(int i = 1; i <= N; i++) {
    if(visit[i] == 0) {
      queue<int> q;
      q.push(i);
      visit[i] = 1;

      while(!q.empty()) {
        int now = q.front();
        q.pop();

        for(int next : link[now]) {
          if(visit[next] == 0) {
            q.push(next);
            visit[next] = 1;
          }
        }
      }
      answer++;
    }
  }

  cout << answer << '\n';
  
  return 0;
}