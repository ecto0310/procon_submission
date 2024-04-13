// Date: Sat, 13 Apr 2024 16:16:35 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  for (ll i = 0; i < N; i++) {
    cin >> A[i];
  }
  ll sum = 0;
  for (ll i : A) {
    sum += i;
  }
  cout << -sum << endl;
}
