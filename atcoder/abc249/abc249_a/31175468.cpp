// Date: Sat, 23 Apr 2022 12:05:34 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl '\n'

int main()
{
    i64 A, B, C, D, E, F, X;
    cin >> A >> B >> C >> D >> E >> F >> X;
    i64 wT = X / (A + C) * (A * B) + min(A, X % (A + C)) * B;
    i64 wA = X / (D + F) * (D * E) + min(D, X % (D + F)) * E;
    if (wT < wA)
    {
        cout << "Aoki" << endl;
    }
    else if (wA < wT)
    {
        cout << "Takahashi" << endl;
    }
    else
    {
        cout << "Draw" << endl;
    }
    return 0;
}
