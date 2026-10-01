#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const ll INF = 1e18;

int main() {
  vector<vector<ll>> dist(n, vector<ll>(n, INF));
  for (int i = 0; i < n; ++i) dist[i][i] = 0;

  for (const auto &[u, v, w] : edges)
    dist[u][v] = min(dist[u][v], w);

  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (dist[i][k] != INF && dist[k][j] != INF) {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
  }

  bool negative_cycle = false;
  for (int i = 0; i < n; ++i) {
    if (dist[i][i] < 0) negative_cycle = true;
  }
}
