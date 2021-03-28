// Date: Sun, 28 Mar 2021 12:02:35 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main() {
    i64 T;
    cin >> T;
    for (i64 _ = 0; _ < T; _++) {
        i64 N;
        cin >> N;
        if (N % 2 != 0) {
            cout << "Odd" << endl;
        } else if (N % 4 == 0) {
            cout << "Even" << endl;
        } else {
            cout << "Same" << endl;
        }
    }
    return 0;
}
