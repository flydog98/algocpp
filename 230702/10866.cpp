// S4 10866 덱

#include <iostream>
#include <string.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, X;
  int deque[20001];
  int head = 10000;
  int tail = 10001;
  string command;

  cin >> N;

  memset(deque, 0, sizeof(deque));

  for(int i = 0; i < N; i++) {
    cin >> command;

    if(command == "push_front") {
      cin >> X;
      deque[head] = X;
      head--;
    }
    else if(command == "push_back") {
      cin >> X;
      deque[tail] = X;
      tail++;
    }
    else if(command == "pop_front") {
      if(head + 1 == tail) {
        cout << -1 << '\n';
      }
      else {
        head++;
        cout << deque[head] << '\n';
      }
    }
    else if(command == "pop_back") {
      if(head + 1 == tail) {
        cout << -1 << '\n';
      }
      else {
        tail--;
        cout << deque[tail] << '\n';
      }
    }
    else if(command == "size") {
      cout << tail - head - 1 << '\n';
    }
    else if(command == "empty") {
      if(head + 1 == tail) {
        cout << 1 << '\n';
      }
      else {
        cout << 0 << '\n';
      }
    }
    else if(command == "front") {
      if(head + 1 == tail) {
        cout << -1 << '\n';
      }
      else {
        cout << deque[head + 1] << '\n';
      }
    }
    else if(command == "back") {
      if(head + 1 == tail) {
        cout << -1 << '\n';
      }
      else {
        cout << deque[tail - 1] << '\n';
      }
    }
  }

  return 0;
}