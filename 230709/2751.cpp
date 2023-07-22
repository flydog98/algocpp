// S5 2751 수 정렬하기 2

#include <iostream>

using namespace std;

void merge(int numbers[], int sorted[], int left, int mid, int right) {
  int i, j, k, l;
  i = left;
  j = mid + 1;
  k = left;

  while(i <= mid && j <= right) {
    if(numbers[i] <= numbers[j]) {
      sorted[k++] = numbers[i++];
    }
    else {
      sorted[k++] = numbers[j++];
    }
  }

  if(i > mid) {
    for(l = j; l <= right; l++) {
      sorted[k++] = numbers[l];
    }
  }
  else {
    for (l = i; l <= mid; l++) {
      sorted[k++] = numbers[l];
    }
  }

  for(l = left; l <= right; l++) {
    numbers[l] = sorted[l];
  }
}

void merge_sort(int numbers[], int sorted[], int left, int right) {
  int mid = (left + right) / 2;

  if(left < right) {
    merge_sort(numbers, sorted, left, mid);
    merge_sort(numbers, sorted, mid + 1, right);
    merge(numbers, sorted, left, mid, right);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N = 0;
  int temp = 0;

  cin >> N;

  int numbers[N];
  int sorted[N];

  for(int i = 0; i < N; i++) {
    cin >> temp;

    numbers[i] = temp;
  }

  merge_sort(numbers, sorted, 0, N - 1);

  for(int i = 0; i < N; i++) {
    cout << numbers[i] << '\n';
  }
  
  return 0;
}
