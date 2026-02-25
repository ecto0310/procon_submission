// Date: Wed, 25 Feb 2026 10:49:47 +0000
// Language: C++23 (GCC 15.2.0)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  string a, b;
  cin >> a >> b;
  ll t = stoi(a + b);
  ll ts = sqrt(t);
  if (t == ts * ts) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
