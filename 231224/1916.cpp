// 1916 최소비용 구하기

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> p;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M;
  int a, b;

  cin >> N >> M;

  vector<vector<p> > line(N + 1, vector<p>(0));
  vector<int> value(N + 1, -1);

  for(int i = 0; i < M; i++) {
    int u, v, w;

    cin >> u >> v >> w;

    line[u].push_back(make_pair(v, w));
  }

  cin >> a >> b;

  priority_queue<p, vector<p>, greater<p> > pq;
  value[a] = 0;

  for(int i = 0; i < line[a].size(); i++) {
    int to = line[a][i].first;
    int val = line[a][i].second;
    pq.push(make_pair(val, to));
    if(value[to] == -1 || value[to] > val) {
      value[to] = val;
    }
  }

  while(!pq.empty()) {
    int now = pq.top().second;
    int nowval = pq.top().first;

    pq.pop();

    if(value[now] != -1 && value[now] < nowval) {
      continue;
    }

    for(int i = 0; i < line[now].size(); i++) {
      int next = line[now][i].first;
      int nextval = line[now][i].second;

      if(value[next] == -1 || value[next] > value[now] + nextval) {
        value[next] = value[now] + nextval;
        pq.push(make_pair(value[next], next));
      }
    }
  }

  cout << value[b] << '\n';

  return 0;
}
