// S2 1260 DFS와 BFS

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

void dfs(vector<vector<int> >& link, vector<int>& visit, int now) {
  visit[now] = 1;
  cout << now << ' ';

  for(int next : link[now]) {
    if(visit[next] == 0) {
      dfs(link, visit, next);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M, V, a, b;

  cin >> N >> M >> V;

  vector<vector<int> > link(N + 1, vector <int>());
  vector<int> visit(N + 1, 0);

  for(int i = 0; i < M; i++) {
    cin >> a >> b;
    link[a].push_back(b);
    link[b].push_back(a);
  }

  for(int i = 1; i <= N; i++) {
    sort(link[i].begin(), link[i].end());
  }

  dfs(link, visit, V);
  cout << '\n';

  for(int i = 0; i <= N; i++) {
    visit[i] = 0;
  }

  queue<int> q;
  q.push(V);
  visit[V] = 1;

  while(!q.empty()) {
    int now = q.front();
    q.pop();
    cout << now << ' ';
    
    for(int next : link[now]) {
      if(visit[next] == 0) {
        q.push(next);
        visit[next] = 1;
      }
    }
  }
  cout << '\n';

  return 0;
}