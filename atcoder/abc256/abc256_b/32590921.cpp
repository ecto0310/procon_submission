// Date: Sun, 19 Jun 2022 12:06:32 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl '\n'

int main()
{
    i64 N;
    cin >> N;
    vector<i64> A(N);
    for (i64 i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    vector<bool> m(4);
    i64 P = 0;
    for (i64 i = 0; i < N; i++)
    {
        m[0] = true;
        for (i64 j = 3; 0 <= j; j--)
        {
            if (!m[j])
            {
                continue;
            }
            m[j] = false;
            if (4 <= j + A[i])
            {
                P++;
            }
            else
            {
                m[j + A[i]] = true;
            }
        }
    }
    cout << P << endl;
    return 0;
}
