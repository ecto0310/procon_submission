// Date: Mon, 07 Apr 2025 04:22:12 +0000
// Language: C++ 20 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll A;
  cin >> A;
  if (400 % A == 0) {
    cout << 400 / A << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}
