// Date: Sun, 11 Apr 2021 12:11:50 +0000
// Language: C++ (GCC 9.2.1)
#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main() {
    i64 R, X, Y;
    cin >> R >> X >> Y;
    if (sqrtl(X * X + Y * Y) < R) {
        cout << 2 << endl;
    } else {
        cout << (i64) ceill(sqrtl(X * X + Y * Y) / R) << endl;
    }
    return 0;
}
