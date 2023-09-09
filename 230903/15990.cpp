// 15990 1, 2, 3 더하기 5

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll DIV = 1000000009;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  vector<ll> end1{0, 1, 0, 1};
  vector<ll> end2{0, 0, 1, 1};
  vector<ll> end3{0, 0, 0, 1};

  for(int i = 4; i <= 100000; i++) {
    end1.push_back((end2[i - 1] + end3[i - 1]) % DIV);
    end2.push_back((end1[i - 2] + end3[i - 2]) % DIV);
    end3.push_back((end1[i - 3] + end2[i - 3]) % DIV);
  }

  cin >> T;

  while(T--) {
    int n;

    cin >> n;

    cout << (end1[n] + end2[n] + end3[n]) % DIV << '\n';
  }
  
  return 0;
}