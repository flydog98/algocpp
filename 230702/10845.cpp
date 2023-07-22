// S4 10845 큐

#include <iostream>
#include <string.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, X;
  int queue[10001];
  int i_pointer = 0;
  int o_pointer = 0;
  string command;

  cin >> N;

  memset(queue, 0, sizeof(queue));

  for(int i = 0; i < N; i++) {
    cin >> command;

    if(command == "push") {
      cin >> X;
      queue[i_pointer] = X;
      i_pointer++;
    }
    else if(command == "pop") {
      if(o_pointer == i_pointer) {
        cout << -1 << '\n';
      }
      else {
        cout << queue[o_pointer] << '\n';
        o_pointer++;
      }
    }
    else if(command == "size") {
      cout << i_pointer - o_pointer << '\n';
    }
    else if(command == "empty") {
      if(i_pointer == o_pointer) {
        cout << 1 << '\n';
      }
      else {
        cout << 0 << '\n';
      }
    }
    else if(command == "front") {
      if(i_pointer == o_pointer) {
        cout << -1 << '\n';
      }
      else {
        cout << queue[o_pointer] << '\n';
      }
    }
    else if(command == "back") {
      if(i_pointer == o_pointer) {
        cout << -1 << '\n';
      }
      else {
        cout << queue[i_pointer - 1] << '\n';
      }
    }
  }

  return 0;
}