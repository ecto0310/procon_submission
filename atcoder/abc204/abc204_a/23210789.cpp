// Date: Sun, 06 Jun 2021 12:01:13 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    i64 x, y;
    cin >> x >> y;
    if (x == y) {
        cout << x << endl;
    } else {
        cout << 3 - x - y << endl;
    }
    return 0;
}
