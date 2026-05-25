// Date: Mon, 25 May 2026 11:22:17 +0000
// Language: C++23 (GCC 15.2.0)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll N;
  cin >> N;
  vector<ll> X(N + 2), Y(N + 2);
  for (int i = 1; i <= N; i++) {
    cin >> X[i] >> Y[i];
  }
  long double ans = 0;
  for (int i = 0; i < N + 1; i++) {
    ans +=
        hypot((long double)(X[i] - X[i + 1]), (long double)(Y[i] - Y[i + 1]));
  }
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}
