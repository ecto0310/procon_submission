// Date: Sat, 06 Jan 2024 12:08:43 +0000
// Language: C++ 20 (gcc 12.2)
#include <bits/stdc++.h>

using ll = int64_t;
using namespace std;

int main() {
  ll N, Q;
  cin >> N >> Q;
  deque<pair<ll, ll>> deq;
  for (ll i = 1; i <= N; i++) {
    deq.push_back({i, 0});
  }
  for (ll _ = 0; _ < Q; _++) {
    ll t;
    cin >> t;
    if (t == 1) {
      pair<ll, ll> p = deq.front();
      string C;
      cin >> C;
      if (C == "R") {
        p.first++;
      } else if (C == "L") {
        p.first--;
      } else if (C == "U") {
        p.second++;
      } else if (C == "D") {
        p.second--;
      }
      deq.push_front(p);
      deq.pop_back();
    } else if (t == 2) {
      ll p;
      cin >> p;
      p--;
      cout << deq[p].first << " " << deq[p].second << endl;
    }
  }
  return 0;
}
