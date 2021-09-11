// Date: Sat, 11 Sep 2021 12:02:44 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
    vector<i64> P(26);
    for (i64 i = 0; i < 26; i++)
    {
        cin >> P[i];
    }
    for (i64 i = 0; i < 26; i++)
    {
        cout << (char)('a' + P[i] - 1);
    }
    return 0;
}
