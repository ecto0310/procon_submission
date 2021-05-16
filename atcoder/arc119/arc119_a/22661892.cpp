// Date: Sun, 16 May 2021 12:03:25 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main() {
    i64 N;
    cin >> N;
    i64 ans = 1e18;
    for (i64 i = 0; i < 64; i++) {
        i64 a = N >> i;
        ans = min(ans, a + i + (N - (a << i)));
    }
    cout << ans << endl;
    return 0;
}
