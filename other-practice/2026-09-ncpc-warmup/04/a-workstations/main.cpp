#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m;
  cin >> n >> m;

  vector<pair<ll, ll>> intervals(n);
  for (int i = 0; i < n; ++i) {
    ll a, s;
    cin >> a >> s;

    ll b = a + s;
    intervals[i] = {b, a}; // {end, start}
  }

  sort(intervals.begin(), intervals.end());

  // for (const auto &[b, a] : intervals) cerr << "[" << a << ", " << b << "]" << " ";
  // cerr << "\n";

  vector<ll> last_end;
  ll unlocks = 0;

  for (const auto &[b, a] : intervals) {
    bool found_valid = false;

    for (size_t i = 0; i < last_end.size(); ++i) {
      ll e = last_end[i];
      if (e <= a) {
        found_valid = true;
        // cerr << "[" << a << ", " << b << "], " << e << "\n";
        if (a - e + 1 >= m) {
          ++unlocks;
        }
        last_end[i] = b;
        break;
      }
    }

    if (!found_valid) {
      ++unlocks;
      last_end.push_back(b);
    }
  }

  cout << unlocks << "\n";
}
