// Date: Thu, 11 Apr 2024 10:47:15 +0000
// Language: C++ 20 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll N;
  cin >> N;
  vector<ll> a(N);
  for (ll i = 0; i < N; i++) {
    cin >> a[i];
  }
  map<ll, ll> m;
  ll an = 0;
  for (ll i = 0; i < N; i++) {
    if (3200 <= a[i]) {
      an++;
    } else {
      m[a[i] / 400]++;
    }
  }
  cout << max(1LL, (ll)m.size()) << " " << m.size() + an << endl;
  return 0;
}
