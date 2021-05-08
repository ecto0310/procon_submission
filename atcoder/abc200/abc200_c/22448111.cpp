// Date: Sat, 08 May 2021 18:00:03 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main() {
    i64 N;
    cin >> N;
    vector<i64> A(N);
    for (i64 i = 0; i < N; i++) {
        cin >> A[i];
    }
    i64 ans = 0;
    map<i64, i64> cnt;
    for (i64 i = 0; i < N; i++) {
        ans += cnt[A[i] % 200];
        cnt[A[i] % 200]++;
    }
    cout << ans << endl;
    return 0;
}
