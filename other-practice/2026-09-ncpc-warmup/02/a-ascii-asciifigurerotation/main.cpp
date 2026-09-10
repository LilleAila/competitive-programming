#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  bool first = true;
  while (true) {
    int n;
    cin >> n;

    if (n == 0) return 0;
    cin.ignore();

    if (!first) cout << "\n";
    first = false;

    vector<string> xs(n);

    size_t max_len = 0;
    for (int i = 0; i < n; ++i) {
      string x;
      getline(cin, x);
      xs[i] = x;
      max_len = max(max_len, x.size());
    }

    for (string& x : xs) {
      x.resize(max_len, ' ');
    }

    vector<string> rotated(max_len, string(n, ' '));

    for (int i = 0; i < n; ++i) {
      for (size_t j = 0; j < max_len; ++j) {
        char c = xs[i][j];
        char result = c == '-' ? '|' : c == '|' ? '-' : c;
        rotated[j][n - 1 - i] = result;
      }
    }

    for (string& x : rotated) {
      x.erase(x.find_last_not_of(" ") + 1);
      cout << x << "\n";
    }
  }
}
