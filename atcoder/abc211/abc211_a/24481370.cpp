// Date: Sat, 24 Jul 2021 12:01:52 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
    i64 A, B;
    cin >> A >> B;
    cout << fixed << setprecision(10) << (double)(A - B) / 3 + B << endl;
    return 0;
}
