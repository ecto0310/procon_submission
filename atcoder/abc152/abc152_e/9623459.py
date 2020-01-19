// Date: Sun, 19 Jan 2020 13:00:48 +0000
// Language: Python (3.4.3)
from fractions import gcd

def lcm(x, y):
  return (x * y) // gcd(x, y)

n = int(input())
a = list(map(int,input().split()))
g = a[0]
for i in range(n):
  g = lcm(g,a[i])
ans = 0
for i in range(n):
  ans += g // a[i]
print(ans%1000000007)
