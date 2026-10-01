import math

max_n = 320000
prime = [True for _ in range(max_n + 1)]
prime[0], prime[1] = False, False

for p in range(2, int(math.sqrt(max_n)) + 1):
    if prime[p]:
        for i in range(p * p, max_n + 1, p):
            prime[i] = False

primes = [i for i in range(max_n) if prime[i]]

n = int(input())

for i in range(n):
    x = int(input())

    representations = []
    for p in primes:
        if p > x / 2:
            break
        if prime[x-p]:
            representations.append((p, x-p))

    print(f"{x} has {len(representations)} representation(s)")
    for (a, b) in representations:
        print(f"{a}+{b}")
    print()
