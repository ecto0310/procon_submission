// Date: Sun, 18 Feb 2024 03:09:24 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll N, M, K;
  cin >> N >> M >> K;
  ll ng = 0, ok = 1e18;
  ll g = lcm(N, M);
  auto check = [&](ll mid) -> bool {
    ll c = mid / N + mid / M - (mid / g) * 2;
    return K <= c;
  };
  while (1 < ok - ng) {
    ll mid = (ok + ng) / 2;
    if (check(mid)) {
      ok = mid;
    } else {
      ng = mid;
    }
  }
  cout << ok << endl;
  return 0;
}
