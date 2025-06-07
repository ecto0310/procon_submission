// Date: Sat, 07 Jun 2025 12:51:43 +0000
// Language: C++ 20 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

void solve() {
  ll N;
  string S;
  cin >> N >> S;
  ll left = 0;
  for (ll i = 0; i < N - 1; i++) {
    if (S[i + 1] < S[i]) {
      left = i;
      break;
    }
  }
  ll right = N - 1;
  for (ll i = left + 1; i < N; i++) {
    if (S[left] < S[i]) {
      right = i - 1;
      break;
    }
  }
  cout << S.substr(0, left) << S.substr(left + 1, right - left) << S[left]
       << S.substr(right + 1, N - right - 1) << endl;
}

int main() {
  ll T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
