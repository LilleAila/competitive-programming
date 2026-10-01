#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<int> disc;
vector<int> low;
vector<pair<int, int>> bridges;
int timer;

void dfs(int u, int p = -1) {
  disc[u] = low[u] = ++timer;

  for (int v : adj[u]) {
    if (v == p) continue;

    if (disc[v]) low[u] = min(low[u], disc[v]);
    else {
      dfs(v, u);
      low[u] = min(low[u], low[v]);
      if (low[v] > disc[u]) bridges.push_back({u, v});
    }
  }
}

int main() {
  int n = 5;
  adj.resize(n);

  // Triangle (0, 1, 2)
  adj[0].push_back(1); adj[1].push_back(0);
  adj[1].push_back(2); adj[2].push_back(1);
  adj[2].push_back(0); adj[0].push_back(2);

  // Bridge between 2 and 3
  adj[2].push_back(3); adj[3].push_back(2);

  // Node 3 connected to 4
  adj[3].push_back(4); adj[4].push_back(3);

  disc.assign(n, 0);
  low.assign(n, 0);
  bridges.clear();
  timer = 0;
  for (int i = 0; i < n; ++i) if (!disc[i]) dfs(i);

  for (const auto &[u, v] : bridges) cout << u << ", " << v << "\n";
}
