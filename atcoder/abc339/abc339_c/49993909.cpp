// Date: Sun, 04 Feb 2024 07:13:15 +0000
// Language: C++ 20 (gcc 12.2)
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
  for (ll i = 0; i < N - 1; i++) {
    A[i + 1] += A[i];
  }
  cout << -min(*min_element(A.begin(), A.end()), 0LL) + A[N - 1] << endl;
  return 0;
}
