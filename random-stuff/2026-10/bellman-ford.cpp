#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const ll INF = LLONG_MAX / 3;

// Se her jeg brukte en edge i stedet for tuple, er du fornøyd nå???
struct Edge {
  int u, v, w;
};

int main() {
  vector<ll> dist(n, INF);
  dist[source] = 0;

  for (int i = 0; i < n - 1; ++i) {
    for (const auto &e : edges) {
      if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
        dist[e.v] = dist[e.u] + e.w;
      }
    }
  }

  bool negative_cycle = false;
  for (const auto &e : edges) {
    if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
      negative_cycle = true;
      break;
    }
  }
}
