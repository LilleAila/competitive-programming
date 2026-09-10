#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, h;
  cin >> n >> h;

  vector<int> stalagmite(h+1, 0);
  vector<int> stalactite(h+1, 0);

  for (int i = 0; i < n; ++i) {
    int size;
    cin >> size;

    if (i % 2 == 0) {
      ++stalagmite[size];
    } else {
      ++stalactite[size];
    }
  }

  for (int i = h - 1; i >= 1; --i) {
    stalagmite[i] += stalagmite[i + 1];
    stalactite[i] += stalactite[i + 1];
  }

  int min_obstacles = n + 1;
  int c = 0;

  for (int i = 1; i <= h; ++i) {
    int obstacles1 = stalagmite[i];
    int obstacles2 = stalactite[h - i + 1];
    int obstacles = obstacles1 + obstacles2;

    if (obstacles < min_obstacles) {
      min_obstacles = obstacles;
      c = 1;
    } else if (min_obstacles == obstacles) {
      ++c;
    }
  }

  cout << min_obstacles << " " << c << "\n";
}
