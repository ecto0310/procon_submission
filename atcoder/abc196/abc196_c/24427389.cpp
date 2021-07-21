// Date: Wed, 21 Jul 2021 11:39:22 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main() {
    i64 N;
    cin >> N;
    i64 ans = 0;
    for (i64 i = 0;; i++) {
        if (N < stoll(to_string(i) + to_string(i))) {
            cout << i - 1 << endl;
            break;
        }
    }
    return 0;
}
