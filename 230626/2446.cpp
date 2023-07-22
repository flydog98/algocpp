// B3 2446 별 찍기 - 9

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, front, back;

  cin >> N;

  for (int i = 0; i < N; i++) {
    string line = "";
    front = i;
    back = 2 * N - 1 - 2 * i;

    for(int j = 0; j < front; j++) {
      line += ' ';
    }
    for(int j = 0; j < back; j++) {
      line += '*';
    }

    cout << line << '\n';
  }

  for(int i = 1; i < N; i++) {
    string line = "";
    front = N - 1 - i;
    back = 1 + i * 2;

    for(int j = 0; j < front; j++) {
      line += ' ';
    }
    for(int j = 0; j < back; j++) {
      line += '*';
    }

    cout << line << '\n';
  }

  return 0;
}