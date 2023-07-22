// B1 10798 세로읽기

#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<vector<char> > board(5, vector<char>(15, ' '));

  for(int i = 0; i < 5; i++) {
    string input;
    cin >> input;
    for(int j = 0; j < input.length(); j++) {
      board[i][j] = input[j];
    }
  }

  for(int j = 0; j < 15; j++) {
    for(int i = 0; i < 5; i++) {
      if(board[i][j] != ' ') {
        cout << board[i][j];
      }
    }
  }
  cout << '\n';

  return 0;
}