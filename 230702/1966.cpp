// S3 1966 프린터 큐

#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> p;

int getmax(int* pc) {
  for(int i = 9; i >= 0; i--) {
    if(pc[i] != 0){
      return i;
    }
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int tc;
  int N, M;
  int temp;
  queue<p> priority;
  p front;
  int pc[10];
  int pmax, count;

  cin >> tc;

  while(tc--) {
    for(int i = 0; i < 10; i++) {
      pc[i] = 0;
    }
    pmax = 0;
    count = 1;
    while(!priority.empty()) priority.pop();

    cin >> N >> M;
    for(int i = 0; i < N; i++) {
      cin >> temp;
      priority.push(make_pair(temp, i));
      pc[temp]++;
    }

    pmax = getmax(pc);
    while(true) {
      front = priority.front();
      if(front.first == pmax) {
        if(front.second == M) {
          cout << count << '\n';
          break;
        }
        else {
          priority.pop();
          pc[pmax]--;
          count++;
          pmax = getmax(pc);
        }
      }
      else {
        priority.pop();
        priority.push(front);
      }
    }
  }

  return 0;
}