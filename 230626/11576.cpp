// S5 11576 Base Conversion

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int A, B, m;
  int temp;
  int decimal = 0;
  vector<int> stack;

  cin >> A >> B >> m;

  int multiply = pow(A, m - 1);
  for(int i = m - 1; i >= 0; i--) {
    cin >> temp;
    decimal += temp * multiply;
    multiply /= A;
  }

  multiply = B;
  while(decimal) {
    temp = decimal % multiply;
    stack.push_back(temp / (multiply / B));
    decimal -= temp;
    multiply *= B;
  }

  for(int i = stack.size() - 1; i >= 0; i--) {
    cout << stack[i] << ' ';
  }
  cout << '\n';


  return 0;
}