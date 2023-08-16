// Date: Wed, 16 Aug 2023 16:11:27 +0000
// Language: C++17
#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;

const i64 val = 2023;

bool solve() {
    i64 n;
    cin >> n;
    if (n == 0) {
        return false;
    }
    i64 ans = 1e9, ind = -1;
    for (i64 i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (abs(val - a) < abs(ans - val)) {
            ans = a;
            ind = i;
        }
    }
    cout << ind + 1 << endl;
    return true;
}

int main() {
    while (solve()) {
    }
}
