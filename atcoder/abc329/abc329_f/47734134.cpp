// Date: Sat, 18 Nov 2023 14:25:09 +0000
// Language: C++ 20 (gcc 12.2)
#include <bits/stdc++.h>

using ll = int64_t;
using namespace std;

int main() {
  ll N, Q;
  cin >> N >> Q;
  vector<ll> C(N), a(Q), b(Q);
  for (ll &i : C) {
    cin >> i;
  }
  for (ll i = 0; i < Q; i++) {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
  }
  vector<set<ll>> s(N);
  for (ll i = 0; i < N; i++) {
    s[i].insert(C[i]);
  }
  for (ll i = 0; i < Q; i++) {
    if (s[b[i]].size() < s[a[i]].size()) {
      s[a[i]].merge(s[b[i]]);
      swap(s[a[i]], s[b[i]]);
    } else {
      s[b[i]].merge(s[a[i]]);
    }
    s[a[i]].clear();
    cout << s[b[i]].size() << endl;
  }

  return 0;
}
