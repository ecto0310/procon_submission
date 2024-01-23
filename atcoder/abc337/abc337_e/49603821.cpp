// Date: Tue, 23 Jan 2024 11:28:30 +0000
// Language: C++ 20 (gcc 12.2)
#include <bits/stdc++.h>

using ll = int64_t;
using namespace std;

int main() {
  ll N;
  cin >> N;
  ll M = 0;
  while ((1 << M) < N) {
    M++;
  }
  cout << M << endl;
  for (ll i = 0; i < M; i++) {
    vector<ll> d;
    for (ll j = 0; j < N; j++) {
      if ((j >> i) & 1) {
        d.push_back(j);
      }
    }
    ll size = d.size();
    cout << size << " ";
    for (ll j = 0; j < size; j++) {
      cout << d[j] + 1;
      if (j + 1 == size) {
        cout << endl;
      } else {
        cout << " ";
      }
    }
  }
  string S;
  cin >> S;
  ll ans = 0;
  for (ll i = 0; i < M; i++) {
    if (S[i] == '1') {
      ans |= 1 << i;
    }
  }
  cout << ans + 1 << endl;
  return 0;
}
