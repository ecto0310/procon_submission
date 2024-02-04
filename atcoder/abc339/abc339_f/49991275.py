// Date: Sun, 04 Feb 2024 05:40:47 +0000
// Language: Python (PyPy 3.10-v7.3.12)
N = int(input())
count = {}
for i in range(N):
    A = int(input())
    count[A] = count.setdefault(A, 0) + 1 

ans = 0
for (k1, v1) in count.items():
    for (k2, v2) in count.items():
        if k1 % k2 == 0 and k1 // k2 in count:
            ans += v1 * v2 * count[k1 // k2]

print(ans)
