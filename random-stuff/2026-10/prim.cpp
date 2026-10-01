#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int main() {
  vector<vector<pair<int, int>>> adj(n); // {v, weight}
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {weight, u}
  vector<bool> visited(n, false);
  int total_weight = 0;
  int used = 0;

  pq.push({0, 0});

  while (!pq.empty()) {
    auto [weight, u] = pq.top();
    pq.pop();

    if (visited[u]) continue;
    visited[u] = true;
    total_weight += weight;
    ++used;

    for (const auto &[v, w] : adj[u])
      if (!visited[v]) pq.push({w, v});
  }
}
