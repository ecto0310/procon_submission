// Date: Sat, 18 Nov 2023 14:12:34 +0000
// Language: C++ 20 (gcc 12.2)
#include <bits/stdc++.h>

using ll = int64_t;
using namespace std;

int main() {
  ll N, M;
  string S, T;
  cin >> N >> M >> S >> T;
  queue<ll> ind;
  set<ll> use;
  auto check = [&](ll index) -> bool {
    for (ll i = 0; i < M; i++) {
      if (S[i + index] != '#' && S[i + index] != T[i]) {
        return false;
      }
    }
    return true;
  };
  for (ll i = 0; i < N - M + 1; i++) {
    if (check(i)) {
      ind.push(i);
      use.insert(i);
    }
  }
  while (ind.size() != 0) {
    ll p = ind.front();
    ind.pop();
    for (ll i = 0; i < M; i++) {
      S[p + i] = '#';
    }
    for (ll i = max(0L, p - M); i < min(N - M + 1, p + M); i++) {
      if (check(i) && use.count(i) == 0) {
        ind.push(i);
        use.insert(i);
      }
    }
  }
  for (char i : S) {
    if (i != '#') {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
