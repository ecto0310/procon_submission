// Date: Fri, 26 Apr 2024 12:12:41 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll N;
  cin >> N;
  N = 1000 - N;
  ll ans = 0;
  for (ll i : {500, 100, 50, 10, 5, 1}) {
    ans += N / i;
    N %= i;
  }
  cout << ans << endl;
}
