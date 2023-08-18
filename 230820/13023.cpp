// G5 ABCDE

#include <iostream>
#include <vector>

using namespace std;

int dfs(vector<vector<int> >& link, vector<int>& visit, int now, int count) {
  visit[now] = 1;

  if(count == 5) {
    return 1;
  }

  for(int next : link[now]) {
    if(visit[next] == 0) {
      if(dfs(link, visit, next, count + 1) == 1) {
        return 1;
      }
      visit[next] = 0;
    }
  }

  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M, a, b;

  cin >> N >> M;

  vector<vector<int> > link(N, vector <int>());
  vector<int> visit(N, 0);

  for(int i = 0; i < M; i++) {
    cin >> a >> b;
    link[a].push_back(b);
    link[b].push_back(a);
  }

  for(int i = 0; i < N; i++) {
    if(dfs(link, visit, i, 1)) {
      cout << 1 << '\n';
      return 0;
    }
    visit[i] = 0;
  }

  cout << 0 << '\n';

  return 0;
}