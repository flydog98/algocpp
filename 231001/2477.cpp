// 2477 참외밭

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> p;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  int y = 0, x = 0;
  int dir = 0, amount = 0;
  int maxX = -100000, minX = 100000, maxY = -100000, minY = 100000;
  p center, corner;
  vector<p> points;
  vector<p> corners;

  cin >> N;

  for(int i = 0; i < 6; i++) {
    cin >> dir >> amount;

    if(dir == 1) {
      x += amount;
    }
    else if (dir == 2) {
      x -= amount;
    }
    else if (dir == 3) {
      y -= amount;
    }
    else {
      y += amount;
    }

    maxX = max(maxX, x);
    maxY = max(maxY, y);
    minX = min(minX, x);
    minY = min(minY, y);

    points.push_back(make_pair(y, x));
  }

  corners.push_back(make_pair(maxY, maxX));
  corners.push_back(make_pair(maxY, minX));
  corners.push_back(make_pair(minY, maxX));
  corners.push_back(make_pair(minY, minX));

  int all = (maxX - minX) * (maxY - minY);

  for(p temp : points) {
    if(temp.first != minY && temp.first != maxY && temp.second != minX && temp.second != maxX) {
      center = temp;
    }
  }

  for(p corn : corners) {
    bool flag = true;
    for(p point : points) {
      if(point == corn) {
        flag = false;
      }
    }
    if(flag) {
      corner = corn;
      break;
    }
  }
  
  cout << (all - abs(center.first - corner.first) * abs(center.second - corner.second)) * N << '\n';

  return 0;
}