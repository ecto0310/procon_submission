// Date: Sat, 07 Oct 2023 12:53:14 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
  ll N;
  cin >> N;
  map<ll, ll> m;
  priority_queue<ll> que;
  for (ll i = 0; i < N; i++) {
    ll S, C;
    cin >> S >> C;
    que.push(S);
    m[S] = C;
  }
  while (que.size() != 0) {
    ll S = que.top();
    que.pop();
    ll C = m[S];
    m[S] %= 2;
    m[S * 2] += C / 2;
    if (2 <= m[S * 2]) {
      que.push(S * 2);
    }
  }
  ll ans = 0;
  for (pair<ll, ll> i : m) {
    ans += i.second;
  }
  cout << ans << endl;
  return 0;
}
