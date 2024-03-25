// Date: Mon, 25 Mar 2024 09:10:37 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll N;
  cin >> N;
  vector<ll> P(N);
  for (ll i = 1; i < N; i++) {
    cin >> P[i];
    P[i]--;
  }
  ll ans = 0, now = N - 1;
  while (now != 0) {
    ans++;
    now = P[now];
  }
  cout << ans << endl;
}
