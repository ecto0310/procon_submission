// Date: Tue, 21 Apr 2026 11:47:13 +0000
// Language: C++23 (GCC 15.2.0)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll N, Q;
  cin >> N >> Q;
  map<ll, multiset<ll>> box;
  map<ll, set<ll>> card;
  for (ll i = 0; i < Q; i++) {
    ll t;
    cin >> t;
    if (t == 1) {
      ll i, j;
      cin >> i >> j;
      box[j].insert(i);
      card[i].insert(j);
    } else if (t == 2) {
      ll i;
      cin >> i;
      for (auto j : box[i]) cout << j << " ";
      cout << endl;
    } else if (t == 3) {
      ll j;
      cin >> j;
      for (auto i : card[j]) cout << i << " ";
      cout << endl;
    }
  }
  return 0;
}
