// Date: Fri, 25 Jul 2025 11:31:50 +0000
// Language: Python (CPython 3.11.4)
import math

def get_primes(n):
    is_prime = [True] * (n+1)
    is_prime[0] = False
    is_prime[1] = False
    for i in range(2, int(n**0.5)+1):
        if is_prime[i]:
            for j in range(i*i, n+1, i):
                is_prime[j] = False
    return [i for i in range(2, n+1) if is_prime[i]]

def main():
    N = int(input())

    lim_pq = int(N ** (1/2))
    primes = get_primes(lim_pq)

    ans = 0
    for p in primes:
        if p**8 <= N:
            ans += 1
        else:
            break

    l = len(primes)
    for i in range(l):
        p = primes[i]
        for j in range(i+1, l):
            q = primes[j]
            if p * q <= lim_pq:
                ans += 1
            else:
                break

    print(ans)

if __name__ == "__main__":
    main()
