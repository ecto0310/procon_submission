// Date: Tue, 26 Mar 2024 08:29:44 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll N, K;
  cin >> N >> K;
  vector<ll> a(N);
  for (ll i = 0; i < N; i++) {
    cin >> a[i];
  }
  vector<vector<ll>> b(K);
  for (ll i = 0; i < N; i++) {
    b[i % K].push_back(a[i]);
  }
  sort(a.begin(), a.end());
  for (ll i = 0; i < K; i++) {
    sort(b[i].begin(), b[i].end());
  }
  for (ll i = 0; i < N; i++) {
    if (a[i] != b[i % K][i / K]) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
