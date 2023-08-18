// S1 1697 숨바꼭질

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, K;
  vector<int> board(100001, 100001);
  queue<int> q;

  cin >> N >> K;

  q.push(N);
  board[N] = 0;

  while(!q.empty()) {
    int now = q.front();
    int nowvalue = board[now];
    q.pop();

    if(now == K) {
      cout << nowvalue << '\n';
      break;
    }

    if(now > 0 && nowvalue + 1 < board[now - 1]) {
      board[now - 1] = nowvalue + 1;
      q.push(now - 1);
    }
    if(now < 100000 && nowvalue + 1 < board[now + 1]) {
      board[now + 1] = nowvalue + 1;
      q.push(now + 1);
    }
    if(now * 2 <= 100000 && nowvalue + 1 < board[now * 2]) {
      board[now * 2] = nowvalue + 1;
      q.push(now * 2);
    }
  }

  return 0;
}