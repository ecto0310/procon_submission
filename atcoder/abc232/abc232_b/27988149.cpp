// Date: Sun, 19 Dec 2021 12:03:51 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
    string S, T;
    cin >> S >> T;
    int d = (T[0] - S[0] + 26) % 26, size = S.size();
    for (int i = 0; i < size; i++)
    {
        if ((T[i] - S[i] + 26) % 26 != d)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
