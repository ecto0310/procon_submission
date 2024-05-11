// Date: Sat, 11 May 2024 12:06:05 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll N, K;
  cin >> N >> K;
  vector<ll> A(N);
  for (ll &i : A) {
    cin >> i;
  }
  ll now = K, ans = 0;
  for (ll i = 0; i < N; i++) {
    if (A[i] <= now) {
      now -= A[i];
    } else {
      ans++;
      now = K - A[i];
    }
  }
  if (now != K) {
    ans++;
  }
  cout << ans << endl;
  return 0;
}
