// Date: Sat, 06 Aug 2022 14:07:20 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl '\n'

int main() {
    vector<int> c(5);
    for (int i = 0; i < 5; i++) {
        cin >> c[i];
    }
    sort(c.begin(), c.end());
    if (c[0] == c[1] && c[3] == c[4] && (c[1] == c[2] || c[2] == c[3])) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
