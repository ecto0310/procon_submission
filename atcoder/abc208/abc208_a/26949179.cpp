// Date: Sun, 31 Oct 2021 07:07:35 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
    i64 A, B;
    cin >> A >> B;
    if (A <= B && B <= 6 * A)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}
