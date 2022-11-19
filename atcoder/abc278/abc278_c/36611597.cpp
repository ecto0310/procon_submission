// Date: Sat, 19 Nov 2022 12:17:46 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl '\n'

int main()
{
    i64 N, Q;
    cin >> N >> Q;
    map<pair<i64, i64>, bool> f;
    for (i64 i = 0; i < Q; i++)
    {
        i64 T, A, B;
        cin >> T >> A >> B;
        A--;
        B--;
        if (T == 1)
        {
            f[{A, B}] = true;
        }
        else if (T == 2)
        {
            f[{A, B}] = false;
        }
        else
        {
            if (f[{A, B}] && f[{B, A}])
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}
