// S5 1181 단어 정렬

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
  if(a.length() == b.length()) {
    return a < b;
  }
  else {
    return a.length() < b.length();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N = 0;
  string temp;
  vector<string> word;
  vector<string>::iterator iter;

  cin >> N;

  for(int i = 0; i < N; i++) {
    cin >> temp;
    word.push_back(temp);
  }

  sort(word.begin(), word.end(), compare);
  word.erase(unique(word.begin(), word.end()), word.end());

  for(iter = word.begin(); iter < word.end(); iter++) {
    cout << *iter << '\n';
  }
  
  return 0;
}
