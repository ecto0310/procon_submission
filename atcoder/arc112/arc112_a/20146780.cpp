// Date: Sat, 13 Feb 2021 12:22:55 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main() {
    i64 T;
    cin >> T;
    for (i64 i = 0; i < T; i++) {
        i64 L, R;
        cin >> L >> R;
        cout << max(0LL, 1 + R - 2 * L + 1) * max(0LL, R - 2 * L + 1) / 2 << endl;
    }
    return 0;
}
