// 1753 최단경로

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

  int V, E, K;

  cin >> V >> E >> K;

  vector<vector<p> > line(V + 1, vector<p>(0));
  vector<int> value(V + 1, -1);

  for(int i = 0; i < E; i++) {
    int u, v, w;

    cin >> u >> v >> w;

    line[u].push_back(make_pair(v, w));
  }

  priority_queue<p, vector<p>, greater<p> > pq;
  value[K] = 0;

  for(int i = 0; i < line[K].size(); i++) {
    int to = line[K][i].first;
    int val = line[K][i].second;
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

  for(int i = 1; i < V + 1; i++) {
    if(value[i] == -1) {
      cout << "INF\n";
    }
    else {
      cout << value[i] << '\n';
    }
  }

  return 0;
}
