// Date: Fri, 18 Apr 2025 10:47:20 +0000
// Language: C++ 20 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll A, B, C;
  cin >> A >> B >> C;
  if (A % 2 == 0 || B % 2 == 0 || C % 2 == 0) {
    cout << 0 << endl;
  } else {
    cout << min({A * B, A * C, B * C}) << endl;
  }
  return 0;
}
