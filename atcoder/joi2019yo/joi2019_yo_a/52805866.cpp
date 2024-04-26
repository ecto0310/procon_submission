// Date: Fri, 26 Apr 2024 12:19:40 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll a, b, c;
  cin >> a >> b >> c;
  ll sum = 0, i = 1;
  for (; sum < c; i++) {
    if (i % 7 == 0) {
      sum += b;
    }
    sum += a;
  }
  cout << i - 1 << endl;
}
