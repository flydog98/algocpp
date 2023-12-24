// 17396 백도어

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<size_t, size_t> p;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M;

  cin >> N >> M;

  vector<vector<p> > line(N, vector<p>(0));
  vector<ll> value(N, -1);
  vector<size_t> sight(N, 0);

  for(size_t i = 0; i < N; i++) {
    cin >> sight[i];
  }
  sight[N - 1] = 0;

  for(int i = 0; i < M; i++) {
    size_t u, v, w;

    cin >> u >> v >> w;

    if(sight[u] == 1 || sight[v] == 1) continue;

    line[u].push_back(make_pair(v, w));
    line[v].push_back(make_pair(u, w));
  }

  priority_queue<p, vector<p>, greater<p> > pq;
  value[0] = 0;

  for(size_t i = 0; i < line[0].size(); i++) {
    size_t to = line[0][i].first;
    size_t val = line[0][i].second;
    pq.push(make_pair(val, to));
    if(value[to] == -1 || value[to] > val) {
      value[to] = val;
    }
  }

  while(!pq.empty()) {
    size_t now = pq.top().second;
    size_t nowval = pq.top().first;

    pq.pop();

    if(value[now] != -1 && value[now] < nowval) {
      continue;
    }

    for(int i = 0; i < line[now].size(); i++) {
      size_t next = line[now][i].first;
      size_t nextval = line[now][i].second;

      if(value[next] == -1 || value[next] > value[now] + nextval) {
        value[next] = value[now] + nextval;
        pq.push(make_pair(value[next], next));
      }
    }
  }

  cout << value[N - 1] << '\n';

  return 0;
}
