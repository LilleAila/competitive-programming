#include <iostream>
#include <utility>
#include <tuple>
#include <numeric>
#include <algorithm>
#include <vector>
using namespace std;

struct DSU {
  vector<int> parent, size;

  DSU(int n) {
    size.assign(n, 1);
    parent.resize(n);
    iota(parent.begin(), parent.end(), 0);
  }

  int find(int n) {
    if (n == parent[n]) return n;
    return parent[n] = find(parent[n]);
  }

  void join(int u, int v) {
    int ru = find(u);
    int rv = find(v);
    if (ru == rv) return;
    if (size[rv] > size[ru]) swap(ru, rv);
    parent[rv] = ru;
    size[ru] += size[rv];
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  while (true) {
    int p, c;
    cin >> p >> c;

    if (p == 0 && c == 0) return 0;

    vector<pair<int, int>> edges(c);
    for (int i = 0; i < c; ++i) {
      cin >> edges[i].first >> edges[i].second;
    }

    bool possible = true;
    for (int i = 0; i < c; ++i) {
      DSU dsu(p);
      for (int j = 0; j < c; ++j) {
        if (j == i) continue;
        auto &[a, b] = edges[j];
        dsu.join(a, b);
      }
      if (dsu.size[dsu.find(0)] != p) {
        possible = false;
        break;
      }
    }

    cout << (possible ? "No" : "Yes") << "\n";
  }
}
