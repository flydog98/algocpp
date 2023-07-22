// G4 17298 오큰수

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

typedef pair<int, int> p;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, temp, number;
  p popped;
  stack<p> s;

  vector<int> list;
  vector<int>::iterator iter;

  cin >> n;

  vector<int> answer(n, -1);

  for(int i = 0; i < n; i++) {
    cin >> temp;
    list.push_back(temp);
  }

  iter = list.begin();
  for(int i = 0; i < n; i++) {
    number = *iter;
    if(!s.empty()) {
      while(!s.empty() && s.top().first < number) {
        popped = s.top();
        s.pop();
        answer[popped.second] = number;
      }
    }
    s.push(make_pair(number, i));
    iter++;
  }

  for(iter = answer.begin(); iter != answer.end(); iter++) {
    cout << *iter << ' ';
  }
  cout << '\n';

  return 0;
}