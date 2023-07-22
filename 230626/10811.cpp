// B2 10811 바구니 뒤집기

#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int>& numbers, int i, int j) {
  int temp = numbers[i];
  numbers[i] = numbers[j];
  numbers[j] = temp;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M;
  int i, j;

  cin >> N >> M;

  vector<int> numbers(N);
  for(int i = 0; i < N; i++) {
    numbers[i] = i + 1;
  }

  while(M--) {
    cin >> i >> j;
    i--;j--;

    while(i < j) {
      swap(numbers, i, j);
      i++;j--;
    }
  }

  for(int i = 0; i < N; i++) {
    cout << numbers[i] << ' ';
  }
  cout << '\n';

  return 0;
}