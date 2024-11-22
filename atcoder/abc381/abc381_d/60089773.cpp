// Date: Fri, 22 Nov 2024 14:11:22 +0000
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
  ll ans = 0;
  auto calc = [&](ll start) {
    vector<ll> count(N + 1);
    ll right = start;
    for (ll left = start; left < N; left += 2) {
      while (right + 2 <= N && A[right] == A[right + 1] &&
             count[A[right]] == 0) {
        count[A[right]]++;
        right += 2;
      }
      ans = max(ans, right - left);
      if (right == left) {
        right += 2;
      } else {
        if (A[left] == A[left + 1]) {
          count[A[left]]--;
        }
      }
    }
  };
  calc(0);
  calc(1);
  cout << ans << endl;
  return 0;
}
