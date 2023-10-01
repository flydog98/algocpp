// 3085 사탕 게임

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> p;

int check(vector<vector<char> >& board, int N) {
  int maxStreak = 0;
  int streak = 1;
  char temp;
  for(int i = 0; i < N; i++) {
    temp = board[i][0];
    for(int j = 1; j < N; j++) {
      if(temp == board[i][j]) {
        streak += 1;
      }
      else {
        streak = 1;
      }
      maxStreak = max(maxStreak, streak);
      temp = board[i][j];
    }

    streak = 1;
  }

  for(int j = 0; j < N; j++) {
    temp = board[0][j];
    for(int i = 1; i < N; i++) {
      if(temp == board[i][j]) {
        streak += 1;
      }
      else {
        streak = 1;
      }
      maxStreak = max(maxStreak, streak);
      temp = board[i][j];
    }

    streak = 1;
  }

  return maxStreak;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  int maxStreak = 0;
  string line;

  cin >> N;

  vector<vector<char> > board(N, vector <char>(N));

  for(int i = 0; i < N; i++) {
    cin >> line;
    for(int j = 0; j < N; j++) {
      board[i][j] = line[j];
    }
  }

  char temp;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N - 1; j++) {
      if(board[i][j] == board[i][j + 1]) continue;
      temp = board[i][j];
      board[i][j] = board[i][j + 1];
      board[i][j + 1] = temp;

      maxStreak = max(maxStreak, check(board, N));
      board[i][j + 1] = board[i][j];
      board[i][j] = temp;
    } 
  }

  for(int i = 0; i < N - 1; i++) {
    for(int j = 0; j < N; j++) {
      if(board[i][j] == board[i + 1][j]) continue;
      temp = board[i][j];
      board[i][j] = board[i + 1][j];
      board[i + 1][j] = temp;

      maxStreak = max(maxStreak, check(board, N));
      board[i + 1][j] = board[i][j];
      board[i][j] = temp;
    } 
  }

  cout << maxStreak << '\n';

  return 0;
}