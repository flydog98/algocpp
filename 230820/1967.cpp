// G4 1967 트리의 지름

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

typedef pair<int, int> p;

int n;

bool compare(p a, p b) {
  return a.first > b.first;
}

p dfs(vector<vector<p> >& link, int start) {
  vector<int> visit(n + 1, 0);
  stack<p> s;
  vector<p> farthest;

  s.push(make_pair(start, 0));
  visit[start] = 1;

  while(!s.empty()) {
    int now = s.top().first;
    int amount = s.top().second;
    s.pop();

    for(p next_p : link[now]) {
      int next = next_p.first, dist = next_p.second;

      if(visit[next] == 0) {
        visit[next] = 1;
        s.push(make_pair(next, amount + dist));
      }
    }

    if(link[now].size() == 1) {
      farthest.push_back(make_pair(amount, now));
    }
  }

  sort(farthest.begin(), farthest.end(), compare);

  return make_pair(farthest[0].first, farthest[0].second);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int u, v, c;

  cin >> n;

  if(n == 1) {
    cout << 0 << '\n';
    return 0;
  }
  if(n == 2) {
    cin >> u >> v >> c;
    cout << c << '\n';
    return 0;
  }

  vector<vector<p> > link(n + 1, vector <p>());

  for(int i = 0; i < n - 1; i++) {
    cin >> u >> v >> c;

    link[u].push_back(make_pair(v, c));
    link[v].push_back(make_pair(u, c));
  }

  p start = dfs(link, 1);

  cout << dfs(link, start.second).first << '\n';

  return 0;
}