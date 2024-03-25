// Date: Mon, 25 Mar 2024 09:08:02 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  string p, q;
  cin >> p >> q;
  vector<ll> i{0, 3, 4, 8, 9, 14, 23};
  cout << abs(i[p[0] - 'A'] - i[q[0] - 'A']) << endl;
}
