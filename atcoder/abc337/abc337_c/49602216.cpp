// Date: Tue, 23 Jan 2024 10:12:18 +0000
// Language: C++ 20 (gcc 12.2)
#include <bits/stdc++.h>

using ll = int64_t;
using namespace std;

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  for (ll i = 0; i < N; i++) {
    cin >> A[i];
  }
  ll now = 0;
  vector<ll> next(N);
  for (ll i = 0; i < N; i++) {
    if (A[i] == -1) {
      now = i;
    } else {
      next[A[i] - 1] = i;
    }
  }
  for (ll i = 0; i < N; i++) {
    cout << now + 1 << " \n"[i + 1 == N];
    now = next[now];
  }
  return 0;
}
