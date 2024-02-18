// Date: Sun, 18 Feb 2024 16:09:20 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

#include <atcoder/segtree>

using ll = long long;
using namespace std;
using namespace atcoder;

int op(int a, int b) { return max(a, b); }

int e() { return 0; };

int main() {
  ll N, Q;
  string S;
  cin >> N >> Q >> S;
  segtree<int, op, e> seg(N + 1);
  for (ll i = 0; i < N - 1; i++) {
    seg.set(i + 1, (S[i] == S[i + 1] ? 1 : 0));
  }
  for (ll _ = 0; _ < Q; _++) {
    ll t, L, R;
    cin >> t >> L >> R;
    if (t == 1) {
      seg.set(L - 1, 1 - seg.get(L - 1));
      seg.set(R, 1 - seg.get(R));
    } else {
      if (seg.prod(L, R) == 0) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
  }
  return 0;
}
