// Date: Sat, 15 Nov 2025 13:00:22 +0000
// Language: C++23 (GCC 15.2.0)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  string X;
  cin >> X;
  sort(X.begin(), X.end());
  for (ll i = 0; i < X.size(); i++) {
    if (X[i] != '0') {
      swap(X[0], X[i]);
      break;
    }
  }
  cout << X << endl;
  return 0;
}
