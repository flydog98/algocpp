// S2 1874 스택 수열

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, input, inputmax = 0;
  stack<int> s;
  vector<char> result;

  cin >> n;

  while(n--) {
    cin >> input;
    if(s.empty() || s.top() < input) {
      for(int i = inputmax; i < input; i++) {
        s.push(i + 1);
        result.push_back('+');
      }
      s.pop();
      result.push_back('-');
      inputmax = input;
    }
    else {
      if(s.top() != input) {
        cout << "NO\n";
        return 0;
      }
      else {
        s.pop();
        result.push_back('-');
      }
    }
  }

  vector<char>::iterator iter;

  for(iter = result.begin(); iter != result.end(); iter++) {
    cout << *iter << '\n';
  }
  
  return 0;
}