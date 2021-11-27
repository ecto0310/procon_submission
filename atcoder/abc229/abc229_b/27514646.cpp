// Date: Sat, 27 Nov 2021 12:03:30 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
    i64 A, B;
    cin >> A >> B;
    while (A != 0 && B != 0)
    {
        if (10 <= A % 10 + B % 10)
        {
            cout << "Hard" << endl;
            return 0;
        }
        A /= 10;
        B /= 10;
    }
    cout << "Easy" << endl;
    return 0;
}
