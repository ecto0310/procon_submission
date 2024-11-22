// Date: Fri, 22 Nov 2024 14:55:26 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll N, Q;
  cin >> N >> Q;
  string S;
  cin >> S;
  vector<ll> c1(N + 1), c2(N + 1);
  vector<ll> sidx;
  for (ll i = 0; i < N; i++) {
    if (S[i] == '1') {
      c1[i + 1]++;
    } else if (S[i] == '2') {
      c2[i + 1]++;
    } else {
      sidx.push_back(i);
    }
    c1[i + 1] += c1[i];
    c2[i + 1] += c2[i];
  }
  for (ll i : c1) {
    cerr << i << " ";
  }
  cerr << endl;
  for (ll i : c2) {
    cerr << i << " ";
  }
  cerr << endl;
  for (ll i : sidx) {
    cerr << i << " ";
  }
  cerr << endl;
  for (ll _ = 0; _ < Q; _++) {
    ll L, R;
    cin >> L >> R;
    L--;
    R--;
    ll lidx = lower_bound(sidx.begin(), sidx.end(), L) - sidx.begin();
    ll ridx = lower_bound(sidx.begin(), sidx.end(), R + 1) - sidx.begin();
    if (lidx == ridx) {
      cout << 0 << endl;
      continue;
    }
    ridx--;
    ll ans = 0;
    while (100 < lidx - ridx) {
      ll mid = (lidx + ridx) / 2;
      ll mv = sidx[mid];
      ll l1 = c1[mv + 1] - c1[L];
      ll r2 = c2[R + 1] - c2[mv];
      // cerr << lidx << " " << ridx << " " << l1 << " " << c1[mv + 1] << " "
      //      << c1[L] << " " << r2 << " " << c2[R + 1] << " " << c2[mv] <<
      //      endl;
      ans = max(ans, 2 * min(l1, r2) + 1);
      if (l1 < r2) {
        ridx = mid - 1;
      } else {
        lidx = mid + 1;
      }
    }
    for (ll i = lidx; i <= ridx; i++) {
      ll mv = sidx[i];
      ll l1 = c1[mv + 1] - c1[L];
      ll r2 = c2[R + 1] - c2[mv];
      ans = max(ans, 2 * min(l1, r2) + 1);
    }
    cout << ans << endl;
  }

  return 0;
}
