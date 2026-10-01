#include <algorithm>
using namespace std;

int binom(int n, int k) {
  if (k > n) return 0;
  k = min(k, n - k);
  int result = 1;

  for (int i = 0; i < k; ++i) {
    result *= (n-i) / (i+1);
  }

  return result;
}
