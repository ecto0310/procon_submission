// Date: Tue, 21 Apr 2026 11:08:14 +0000
// Language: C++23 (GCC 15.2.0)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll N;
  cin >> N;
  vector<string> c(N);
  vector<ll> l(N);
  for (ll i = 0; i < N; i++) cin >> c[i] >> l[i];
  ll sum = 0;
  for (ll i = 0; i < N; i++) {
    sum += l[i];
    if (sum > 100) {
      cout << "Too Long" << endl;
      return 0;
    }
  }
  string S;
  for (ll i = 0; i < N; i++) {
    S += string(l[i], c[i][0]);
  }
  cout << S << endl;
  return 0;
}
