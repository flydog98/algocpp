// S4 4949 균형잡힌 세상

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string input;
  bool balance = true;
  stack<char> stack;

  while(true) {
    getline(cin, input);
    if(input == ".") break;

    balance = true;
    while(!stack.empty()) stack.pop();
    for(int i = 0; i < input.length(); i++) {
      char now = input[i];

      if(now == '(' || now == '[') {
        stack.push(now);
      }
      else if (now == ')') {
        if(!stack.empty() && stack.top() == '(') {
          stack.pop();
        }
        else {
          balance = false;
          break;
        }
      }
      else if (now == ']') {
        if(!stack.empty() && stack.top() == '[') {
          stack.pop();
        }
        else {
          balance = false;
          break;
        }
      }
    }

    if(stack.empty() && balance) {
      cout << "yes\n";
    }
    else {
      cout << "no\n";
    }
  }

  return 0;
}