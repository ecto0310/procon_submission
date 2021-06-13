// Date: Sun, 13 Jun 2021 12:06:09 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main() {
    i64 A, B, C;
    cin >> A >> B >> C;
    if (C % 2 == 0) {
        A = abs(A);
        B = abs(B);
    }
    if (A == B) {
        cout << "=" << endl;
    } else if (A < B) {
        cout << "<" << endl;
    } else if (A > B) {
        cout << ">" << endl;
    }
    return 0;
}
