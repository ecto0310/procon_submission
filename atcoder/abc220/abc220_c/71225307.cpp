// Date: Tue, 25 Nov 2025 11:18:30 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  for (ll i = 0; i < N; i++) cin >> A[i];
  ll X;
  cin >> X;
  ll sum = accumulate(A.begin(), A.end(), 0LL);
  for (ll i = 0; i < N - 1; i++) {
    A[i + 1] += A[i];
  }
  cout << (X / sum) * N +
              (upper_bound(A.begin(), A.end(), X % sum) - A.begin()) + 1
       << endl;
  return 0;
}
