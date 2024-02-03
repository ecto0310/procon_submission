// Date: Sat, 03 Feb 2024 12:22:46 +0000
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
  ll idx = min_element(A.begin(), A.end()) - A.begin();
  if (idx == N - 1) {
    cout << 0 << endl;
  } else if (A[idx] < 0) {
    cout << -A[idx] + A[N - 1] << endl;
  } else {
    cout << A[N - 1] << endl;
  }
  return 0;
}
