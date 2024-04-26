// Date: Fri, 26 Apr 2024 11:36:30 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll R, C;
  cin >> R >> C;
  vector<vector<ll>> A(2, vector<ll>(2));
  for (ll i = 0; i < 2; i++) {
    for (ll j = 0; j < 2; j++) {
      cin >> A[i][j];
    }
  }
  cout << A[R - 1][C - 1] << endl;
}
