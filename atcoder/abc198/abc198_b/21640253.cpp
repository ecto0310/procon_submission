// Date: Sun, 11 Apr 2021 12:04:37 +0000
// Language: C++ (GCC 9.2.1)
#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main() {
    string N;
    cin >> N;
    for (i64 i = 0; i < 10; i++) {
        string t = N;
        reverse(t.begin(), t.end());
        if (t == N) {
            cout << "Yes" << endl;
            return 0;
        }
        N = "0" + N;
    }
    cout << "No" << endl;
    return 0;
}
