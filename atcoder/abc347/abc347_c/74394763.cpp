// Date: Wed, 25 Mar 2026 12:34:04 +0000
// Language: C++23 (GCC 15.2.0)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll N, A, B;
  cin >> N >> A >> B;
  vector<ll> D(N);
  set<ll> t;
  for (ll i = 0; i < N; i++) {
    cin >> D[i];
    t.insert((D[i] - 1) % (A + B));
  }
  t.insert((*t.begin()) + A + B);

  vector<ll> tt(t.begin(), t.end());
  bool ok = false;
  for (ll i = 0; i + 1 < tt.size(); i++) {
    if (B <= tt[i + 1] - tt[i] - 1) {
      ok = true;
    }
  }
  if (ok) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
