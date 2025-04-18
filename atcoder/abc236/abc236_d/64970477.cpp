// Date: Fri, 18 Apr 2025 12:06:23 +0000
// Language: C++ 20 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

const ll MOD = 1000000000 + 7;

int main() {
  ll N;
  cin >> N;
  N *= 2;
  vector<vector<ll>> A(N, vector<ll>(N));
  for (ll i = 0; i < N; i++) {
    for (ll j = i + 1; j < N; j++) {
      cin >> A[i][j];
      A[j][i] = A[i][j];
    }
  }
  vector<bool> use(N);
  auto dfs = [&](auto self, ll n, ll s) -> ll {
    if (n == 0) {
      return s;
    }
    ll ans = 0;
    ll l = 0;
    while (use[l]) {
      l++;
    }
    use[l] = true;
    for (ll r = l + 1; r < N; r++) {
      if (use[r]) {
        continue;
      }
      use[r] = true;
      ans = max(ans, self(self, n - 2, s ^ A[l][r]));
      use[r] = false;
    }
    use[l] = false;
    return ans;
  };
  cout << dfs(dfs, N, 0) << endl;
  return 0;
}
