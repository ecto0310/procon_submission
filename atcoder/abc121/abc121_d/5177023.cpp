// Date: Sun, 28 Apr 2019 12:32:56 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

i64 calc(i64 n)
{
    i64 cnt = (n + 1) / 2;
    i64 ret = cnt % 2;
    if (n % 2 == 0)
        ret ^= n;
    return ret;
}

int main()
{
    i64 a, b;
    cin >> a >> b;
    cout << (calc(a - 1) ^ calc(b)) << endl;
    return 0;
}
