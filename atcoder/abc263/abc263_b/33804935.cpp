// Date: Sat, 06 Aug 2022 12:04:31 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl '\n'

int main() {
    i64 N;
    cin >> N;
    vector<i64> P(N + 1);
    for (int i = 2; i <= N; i++) {
        cin >> P[i];
    }
    i64 ans = 0, now = N;
    while (now != 1) {
        now = P[now];
        ans++;
    }
    cout << ans << endl;
    return 0;
}
