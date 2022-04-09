// Date: Sat, 09 Apr 2022 13:53:57 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl '\n'

int main()
{
    int x[3], y[3];
    for (i64 i = 0; i < 3; i++)
    {
        cin >> x[i] >> y[i];
    }
    cout << (x[0] ^ x[1] ^ x[2]) << " " << (y[0] ^ y[1] ^ y[2]) << endl;
    return 0;
}
