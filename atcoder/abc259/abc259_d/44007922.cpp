// Date: Fri, 28 Jul 2023 08:27:12 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

#include <atcoder/dsu>

using namespace std;
using ll = int64_t;

#ifdef LOCAL
#define cerr cerr << "\033[31m"
#define cout cout << "\033[32m"
#define endl "\033[m" << endl
#endif

int main() {
  ll N;
  cin >> N;
  ll sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;
  vector<tuple<ll, ll, ll>> c(N);
  for (auto &ci : c) {
    ll x, y, r;
    cin >> x >> y >> r;
    ci = {x, y, r};
  }
  atcoder::dsu dsu(N);
  for (ll i = 0; i < N; i++) {
    for (ll j = i + 1; j < N; j++) {
      auto [xi, yi, ri] = c[i];
      auto [xj, yj, rj] = c[j];
      ll l = (xi - xj) * (xi - xj) + (yi - yj) * (yi - yj);
      ll rd = ri - rj, rs = ri + rj;
      if (rd * rd <= l && l <= rs * rs) {
        dsu.merge(i, j);
      }
    }
  }
  ll si = -1, ti = -1;
  for (ll i = 0; i < N; i++) {
    auto [xi, yi, ri] = c[i];
    if ((xi - sx) * (xi - sx) + (yi - sy) * (yi - sy) == ri * ri) {
      si = i;
    }
    if ((xi - tx) * (xi - tx) + (yi - ty) * (yi - ty) == ri * ri) {
      ti = i;
    }
  }
  if (dsu.same(si, ti)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
