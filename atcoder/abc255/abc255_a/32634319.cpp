// Date: Tue, 21 Jun 2022 02:15:13 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl '\n'

int main()
{
    int R, C;
    cin >> R >> C;
    vector<vector<i64>> A(2, vector<i64>(2));
    for (auto &i : A)
    {
        for (auto &j : i)
        {
            cin >> j;
        }
    }
    cout << A[R - 1][C - 1] << endl;
    return 0;
}
