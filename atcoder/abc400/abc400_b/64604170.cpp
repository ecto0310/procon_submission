// Date: Mon, 07 Apr 2025 04:32:02 +0000
// Language: C++ 20 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll N, M;
  cin >> N >> M;
  ll X = 0;
  ll t = 1;
  for (ll i = 0; i <= M; i++) {
    X += t;
    cerr << t << " " << X << endl;
    if (1000000000 < t || 1000000000 < X) {
      cout << "inf" << endl;
      return 0;
    }
    t *= N;
  }
  if (1000000000 < X) {
    cout << "inf" << endl;
  } else {
    cout << X << endl;
  }
  return 0;
}
