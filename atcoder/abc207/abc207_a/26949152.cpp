// Date: Sun, 31 Oct 2021 07:06:23 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
    i64 A, B, C;
    cin >> A >> B >> C;
    cout << A + B + C - min({A, B, C}) << endl;
    return 0;
}
