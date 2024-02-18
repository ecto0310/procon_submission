// Date: Sun, 18 Feb 2024 02:31:42 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  for (ll &i : A) {
    cin >> i;
  }
  vector<pair<ll, ll>> ST(N - 1);
  for (pair<ll, ll> &i : ST) {
    cin >> i.first >> i.second;
  }
  for (ll i = 0; i < N - 1; i++) {
    A[i + 1] += A[i] / ST[i].first * ST[i].second;
  }
  cout << A[N - 1] << endl;
  return 0;
}
