// Date: Sun, 28 Apr 2019 12:03:36 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
    i64 a, b, c;
    cin >> a >> b >> c;
    if (c <= a + b + 1)
        cout << b + c << endl;
    else
        cout << b + a + b + 1 << endl;
    return 0;
}
