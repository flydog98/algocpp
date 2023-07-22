// S3 1929 소수 구하기

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int M, N;

  cin >> M >> N;

  vector<int> numbers(N + 1, 1);
  numbers[0] = 0;
  numbers[1] = 0;

  for(int i = 2; i <= sqrt(N) + 1; i++) {
    if(numbers[i] == 0) continue;
    int value = i * 2;
    while(value <= N) {
      numbers[value] = 0;
      value += i;
    }
  }

  for(int i = M; i <= N; i++) {
    if(numbers[i] == 1) {
      cout << i << '\n';
    }
  }

  return 0;
}