// Date: Fri, 25 Jul 2025 11:02:22 +0000
// Language: C++ 20 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  vector<ll> v(3);
  for (int i = 0; i < 3; ++i) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  if ((v[0] == v[1] && v[1] != v[2]) || (v[0] != v[1] && v[1] == v[2])) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
