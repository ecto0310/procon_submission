// Date: Sat, 14 Dec 2024 12:17:16 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll N, S;
  cin >> N >> S;
  vector<ll> A(2 * N);
  ll lsum = 0;
  for (ll i = 0; i < N; i++) {
    ll t;
    cin >> t;
    A[i] = t;
    A[i + N] = t;
    lsum += t;
  }
  S %= lsum;
  N *= 2;
  ll right = 0, sum = 0;
  bool ans = false;
  for (ll left = 0; left < N; left++) {
    while (right < N && sum + A[right] <= S) {
      sum += A[right];
      right++;
    }
    if (sum == S) {
      ans = true;
    }
    if (right == left) {
      right++;
    } else {
      sum -= A[left];
    }
  }
  if (ans) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
