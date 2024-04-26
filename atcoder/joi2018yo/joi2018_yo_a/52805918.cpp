// Date: Fri, 26 Apr 2024 12:21:05 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  cout << min((n + a - 1) / a * b, (n + c - 1) / c * d) << endl;
}
