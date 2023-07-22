// B1 11655 ROT13

#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string input;

  getline(cin, input);

  for(int i = 0; i < input.length(); i++) {
    char ch = input[i];
    if('a' <= ch && ch <= 'm') {
      ch += 13;
    }
    else if('n' <= ch && ch <= 'z') {
      ch -= 13;
    }
    else if('A' <= ch && ch <= 'M') {
      ch += 13;
    }
    else if('N' <= ch && ch <= 'Z') {
      ch -= 13;
    }
    input[i] = ch;
  }

  cout << input << '\n';

  return 0;
}