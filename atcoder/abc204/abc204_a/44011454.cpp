// Date: Fri, 28 Jul 2023 12:01:06 +0000
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
  ll x, y;
  cin >> x >> y;
  if (x == y) {
    cout << x << endl;
  } else {
    cout << 3 - x - y << endl;
  }
  return 0;
}
