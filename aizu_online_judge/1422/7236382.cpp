// Date: Fri, 23 Dec 2022 13:09:10 +0000
// Language: C++17
#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main() {
    i64 n, r;
    cin >> n >> r;
    vector<i64> x(n), y(n), z(n);
    for (i64 i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> z[i];
    }
    double ans = 0;
    for (i64 i = 0; i < n; i++) {
        ans += 4 * M_PI * pow(r, 3) / 3;
        i64 t = (i + 1) % n;
        double d = hypot(x[i] - x[t], y[i] - y[t], z[i] - z[t]);
        ans -= M_PI * pow(r - d / 2, 2) * (2 * r + d / 2) * 2 / 3;
    }
    cout << fixed << setprecision(8) << ans << endl;

    return 0;
}
