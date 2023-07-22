// S4 10828 스택

#include <iostream>
#include <string.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, X;
  int stack[10001];
  int pointer = 0;
  string command;

  cin >> N;

  memset(stack, 0, sizeof(stack));

  for(int i = 0; i < N; i++) {
    cin >> command;

    if(command == "push") {
      cin >> X;
      stack[pointer] = X;
      pointer++;
    }
    else if(command == "pop") {
      if(pointer == 0) {
        cout << -1 << '\n';
      }
      else {
        pointer--;
        cout << stack[pointer] << '\n';
      }
    }
    else if(command == "size") {
      cout << pointer << '\n';
    }
    else if(command == "empty") {
      if(pointer == 0) {
        cout << 1 << '\n';
      }
      else {
        cout << 0 << '\n';
      }
    }
    else if(command == "top") {
      if(pointer == 0) {
        cout << -1 << '\n';
      }
      else {
        cout << stack[pointer - 1] << '\n';
      }
    }
  }

  return 0;
}