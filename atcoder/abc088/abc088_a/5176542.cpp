// Date: Sun, 28 Apr 2019 12:00:58 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
    i64 n, a;
    cin >> n >> a;
    if (n % 500 <= a)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
