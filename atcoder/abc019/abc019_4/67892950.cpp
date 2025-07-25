// Date: Fri, 25 Jul 2025 12:55:47 +0000
// Language: C++ 20 (gcc 12.2)
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll query(ll a, ll b) {
    cout << "? " << a << " " << b << endl;
    ll dist;
    cin >> dist;
    return dist;
}

int main() {
    ll N;
    cin >> N;

    ll max_dist = -1;
    ll f = 1;
    for (ll v = 2; v <= N; ++v) {
        ll dist = query(1, v);
        if (dist > max_dist) {
            max_dist = dist;
            f = v;
        }
    }

    max_dist = -1;
    for (ll v = 1; v <= N; ++v) {
        if (v == f) continue;
        ll dist = query(f, v);
        if (dist > max_dist) {
            max_dist = dist;
        }
    }

    cout << "! " << max_dist << endl;

    return 0;
}
