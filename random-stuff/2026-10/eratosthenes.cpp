#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<bool> prime(MAXN + 1, true);
  prime[0] = false;
  prime[1] = false;

  for (int p = 2; p * p <= MAXN; ++p) {
    if (prime[p]) {
      for (int i = p * p; i <= MAXN; i += p) {
        prime[i] = false;
      }
    }
  }

  vector<int> primes;
  for (int i = 0; i < MAXN; ++i)
    if (prime[i]) primes.push_back(i);
}
