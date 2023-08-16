// Date: Wed, 16 Aug 2023 16:10:18 +0000
// Language: C++17
#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;

const i64 val = 2023;

bool solve() {
    i64 n, m, p, q;
    cin >> n >> m >> p >> q;
    if (n == 0 && m == 0 && p == 0 && p == 0) {
        return false;
    }
    vector<i64> x(m);
    for (i64 i = 0; i < m; i++) {
        cin >> x[i];
    }

    auto calc = [&](vector<i64> &line) {
        vector<i64> num(n);
        for (i64 i = 0; i < n; i++) {
            num[i] = i + 1;
        }
        for (i64 i : line) {
            swap(num[i], num[i - 1]);
        }
        return num[q - 1] == p;
    };
    auto insert = [&](int ni, int mi) {
        vector<i64> line;
        if (mi == 0) {
            line.push_back(ni);
        }
        for (int i = 0; i < m; i++) {
            line.push_back(x[i]);
            if (i + 1 == mi) {
                line.push_back(ni);
            }
        }
        return line;
    };

    if (calc(x)) {
        cout << "OK" << endl;
        return true;
    }
    for (i64 i = 0; i <= m; i++) {
        for (i64 j = 1; j < n; j++) {
            vector<i64> line = insert(j, i);
            if (calc(line)) {
                cout << j << " " << i << endl;
                return true;
            }
        }
    }
    cout << "NG" << endl;
    return true;
}

int main() {
    while (solve()) {
    }
}
