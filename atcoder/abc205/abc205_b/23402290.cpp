// Date: Sun, 13 Jun 2021 12:02:56 +0000
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
    sort(A.begin(), A.end());
    for (i64 i = 0; i < N; i++) {
        if (A[i] != i + 1) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
