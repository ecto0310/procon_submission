// Date: Sun, 06 Jun 2021 12:02:24 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    i64 N;
    cin >> N;
    vector<i64> A(N);
    for (i64 i = 0; i < N; i++) {
        cin >> A[i];
    }
    i64 ans = 0;
    for (i64 i = 0; i < N; i++) {
        if (10 < A[i]) {
            ans += A[i] - 10;
        }
    }
    cout << ans << endl;
    return 0;
}
