// Date: Sat, 06 Mar 2021 03:55:26 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main() {
    i64 N;
    cin >> N;
    vector<i64> x(N), y(N), r(N);
    for (i64 i = 0; i < N; i++) {
        cin >> x[i] >> y[i] >> r[i];
    }
    for (i64 i = 0; i < N; i++) {
        cout << x[i] << " " << y[i] << " " << x[i] + 1 << " " << y[i] + 1 << endl;
    }
    return 0;
}
