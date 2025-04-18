// Date: Fri, 18 Apr 2025 11:13:06 +0000
// Language: C++ 20 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll N, M, X, Y;
  cin >> N >> M >> X >> Y;
  vector<ll> a(N), b(M);
  for (ll &i : a) {
    cin >> i;
  }
  for (ll &i : b) {
    cin >> i;
  }
  ll ans = 0;
  ll i = 0, j = 0;
  while (true) {
    while (j < M && b[j] < a[i] + X) {
      j++;
    }
    if (j == M || b[j] < a[i] + X) {
      break;
    }
    i++;
    ans++;
    while (i < N && a[i] < b[j] + Y) {
      i++;
    }
    if (i == N || a[i] < b[j] + Y) {
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
