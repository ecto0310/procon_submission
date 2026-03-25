// Date: Wed, 25 Mar 2026 12:08:44 +0000
// Language: C++23 (GCC 15.2.0)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll N, Q;
  cin >> N >> Q;
  vector<ll> X(Q), Y(Q);
  for (ll i = 0; i < Q; i++) {
    cin >> X[i] >> Y[i];
  }
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> que;
  for (ll i = 0; i < N; i++) {
    que.push({i + 1, 1});
  }
  for (ll i = 0; i < Q; i++) {
    ll cnt = 0;
    while (0 < que.size() && que.top().first <= X[i]) {
      auto [v, c] = que.top();
      que.pop();
      cnt += c;
    }
    que.push({Y[i], cnt});
    cout << cnt << endl;
  }
  return 0;
}
