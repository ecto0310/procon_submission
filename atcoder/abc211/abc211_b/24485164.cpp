// Date: Sat, 24 Jul 2021 12:03:44 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
    string S[4], ans[4] = {"H", "2B", "3B", "HR"};
    cin >> S[0] >> S[1] >> S[2] >> S[3];
    sort(S, S + 4);
    sort(ans, ans + 4);
    for (int i = 0; i < 4; i++)
    {
        if (S[i] != ans[i])
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
