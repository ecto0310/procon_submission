// Date: Wed, 25 Mar 2026 11:58:52 +0000
// Language: C++23 (GCC 15.2.0)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll N;
  cin >> N;
  vector<ll> S(N), T(N);
  for (ll i = 0; i < N; i++) {
    cin >> S[i];
  }
  for (ll i = 0; i < N; i++) {
    cin >> T[i];
  }
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> que;
  for (ll i = 0; i < N; i++) {
    que.push({T[i], i});
  }
  ll have_cnt = 0;
  vector<ll> ans(N, -1);
  while (0 < que.size()) {
    auto [t, i] = que.top();
    que.pop();
    que.push({t + S[i], (i + 1) % N});
    if (ans[i] == -1) {
      ans[i] = t;
      have_cnt++;
    }
    if (have_cnt == N) {
      break;
    }
  }
  for (ll i = 0; i < N; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}
