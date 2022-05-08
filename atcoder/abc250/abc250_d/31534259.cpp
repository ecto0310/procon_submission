// Date: Sun, 08 May 2022 12:47:24 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl '\n'

const i64 M = 1000000;

bool f(i64 p, i64 q, i64 N)
{
    if (N / (q * q * q) < p)
    {
        return false;
    }
    return p * q * q * q <= N;
}

int main()
{
    i64 N;
    cin >> N;
    vector<bool> pri(M, true);
    for (i64 i = 2; i < M; i++)
    {
        if (pri[i])
        {
            for (i64 j = i * 2; j < M; j += i)
            {
                pri[j] = false;
            }
        }
    }
    vector<i64> p;
    for (i64 i = 2; i < M; i++)
    {
        if (pri[i])
        {
            p.push_back(i);
        }
    }
    i64 size = p.size();
    i64 ans = 0;
    for (i64 i = 0; i < size - 1; i++)
    {
        if (f(p[i], p[i + 1], N))
        {
            i64 l = i + 1;
            i64 r = size + 1;
            while (1 < r - l)
            {
                i64 mid = (r + l) / 2;
                if (f(p[i], p[mid], N))
                {
                    l = mid;
                }
                else
                {
                    r = mid;
                }
            }
            if (r == size + 1)
            {
                return 1;
            }
            ans += l - i;
        }
    }
    cout << ans << endl;
    return 0;
}
