// S4 1764 듣보잡

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M;
  string temp;
  vector<string> notlisten;
  vector<string> notseen;
  vector<string> both;
  vector<string>::iterator iter;

  cin >> N >> M;

  for(int i = 0; i < N; i++) {
    cin >> temp;
    notlisten.push_back(temp);
  }

  for(int i = 0; i < M; i++) {
    cin >> temp;
    notseen.push_back(temp);
  }

  sort(notlisten.begin(), notlisten.end());

  for(iter = notseen.begin(); iter < notseen.end(); iter++) {
    if(binary_search(notlisten.begin(), notlisten.end(), *iter)) {
      both.push_back(*iter);
    }
  }

  sort(both.begin(), both.end());

  cout << both.size() << '\n';

  for(iter = both.begin(); iter < both.end(); iter++) {
    cout << *iter << '\n';
  }

  return 0;
}
