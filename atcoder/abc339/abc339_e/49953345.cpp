// Date: Sat, 03 Feb 2024 12:56:21 +0000
// Language: C++ 20 (gcc 12.2)
#include <bits/stdc++.h>

#include <atcoder/segtree>

using ll = long long;
using namespace std;
using namespace atcoder;

int main() {
  ll N, D;
  cin >> N >> D;
  vector<ll> A(N);
  for (ll &i : A) {
    cin >> i;
  }
  auto op = [](ll a, ll b) { return max(a, b); };
  auto e = []() { return 0LL; };
  ll m = *max_element(A.begin(), A.end());
  segtree<ll, op, e> seg(m + 1);
  for (ll i = 0; i < N; i++) {
    ll t = seg.prod(max(0LL, A[i] - D), min(m, A[i] + D) + 1);
    seg.set(A[i], t + 1);
  }
  cout << seg.all_prod() << endl;
  return 0;
}
