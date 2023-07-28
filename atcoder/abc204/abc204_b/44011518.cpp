// Date: Fri, 28 Jul 2023 12:02:32 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

#ifdef LOCAL
#define cerr cerr << "\033[31m"
#define cout cout << "\033[32m"
#define endl "\033[m" << endl
#endif

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  for (ll &ai : A) {
    cin >> ai;
  }
  ll ans = 0;
  for (ll ai : A) {
    ans += max((ll)0, ai - 10);
  }
  cout << ans << endl;
  return 0;
}
