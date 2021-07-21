// Date: Wed, 21 Jul 2021 11:33:15 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main() {
    string X;
    cin >> X;
    for (char i:X) {
        if (i == '.') {
            break;
        }
        cout << i;
    }
    cout << endl;
    return 0;
}
