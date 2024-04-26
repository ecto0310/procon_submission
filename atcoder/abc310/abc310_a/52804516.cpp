// Date: Fri, 26 Apr 2024 11:31:26 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll N, P, Q;
  cin >> N >> P >> Q;
  vector<ll> D(N);
  for (ll &i : D) {
    cin >> i;
  }
  sort(D.begin(), D.end());
  if (D[0] < P - Q) {
    cout << Q + D[0] << endl;
  } else {
    cout << P << endl;
  }
}
