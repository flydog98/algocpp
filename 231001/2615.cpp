// 2615 오목

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int starty, startx;
  vector<vector<int> > board(19, vector <int>(19));

  for(int i = 0; i < 19; i++) {
    for(int j = 0; j < 19; j++) {
      cin >> board[i][j];
    }
  }

  for(int i = 0; i < 19; i++) {
    vector<int> stack;
    for(int j = 0; j < 19; j++) {
      if(board[i][j] && (stack.empty() || stack.back() == board[i][j])) {
        stack.push_back(board[i][j]);
      } else {
        if(stack.size() == 5) {
          cout << board[i][j - 5] << '\n' << i + 1 << ' ' << j - 4 << '\n';
          return 0;
        }
        stack.clear();
        if(board[i][j]) stack.push_back(board[i][j]);
      }
    }
    if(stack.size() == 5) {
      cout << board[i][18] << '\n' << i + 1 << ' ' << 15 << '\n';
      return 0;
    }
  }

  for(int j = 0; j < 19; j++) {
    vector<int> stack;
    for(int i = 0; i < 19; i++) {
      if(board[i][j] && (stack.empty() || stack.back() == board[i][j])) {
        stack.push_back(board[i][j]);
      } else {
        if(stack.size() == 5) {
          cout << board[i - 5][j] << '\n' << i - 4 << ' ' << j + 1 << '\n';
          return 0;
        }
        stack.clear();
        if(board[i][j]) stack.push_back(board[i][j]);
      }
    }
    if(stack.size() == 5) {
      cout << board[18][j] << '\n' << 15 << ' ' << j + 1 << '\n';
      return 0;
    }
  }

  for(int sum = 0; sum < 37; sum++) {
    vector<int> stack;
    int i = sum < 19 ? sum : 18;
    int j = sum < 19 ? 0 : sum - 18;
    for(; i >= 0 && j <= 18; i--, j++) {

      if(board[i][j] && (stack.empty() || stack.back() == board[i][j])) {
        stack.push_back(board[i][j]);
      } else {
        if(stack.size() == 5) {
          cout << board[i + 5][j - 5] << '\n' << i + 6 << ' ' << j - 4 << '\n';
          return 0;
        }
        stack.clear();
        if(board[i][j]) stack.push_back(board[i][j]);
      }
    }
    if(stack.size() == 5) {
      cout << board[i + 5][j - 5] << '\n' << i + 6 << ' ' << j - 4 << '\n';
      return 0;
    }
  }

  for(int diff = -18; diff <= 18; diff++) {
    vector<int> stack;
    int i = diff < 0 ? -diff : 0;
    int j = diff < 0 ? 0 : diff;
    for(; i <= 18 && j <= 18; i++, j++) {
      if(board[i][j] && (stack.empty() || stack.back() == board[i][j])) {
        stack.push_back(board[i][j]);
      } else {
        if(stack.size() == 5) {
          cout << board[i - 5][j - 5] << '\n' << i - 4 << ' ' << j - 4 << '\n';
          return 0;
        }
        stack.clear();
        if(board[i][j]) stack.push_back(board[i][j]);
      }
    }
    if(stack.size() == 5) {
      cout << board[i - 5][j - 5] << '\n' << i - 4 << ' ' << j - 4 << '\n';
      return 0;
    }
  }

  cout << 0 << '\n';

  return 0;
}