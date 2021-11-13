// Date: Sat, 13 Nov 2021 12:07:45 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
    i64 N, K, A;
    cin >> N >> K >> A;
    A--;
    K--;
    while (K--)
    {
        (A += 1) %= N;
    }
    cout << A + 1 << endl;
    return 0;
}
