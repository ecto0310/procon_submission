// Date: Thu, 11 Apr 2024 10:44:20 +0000
// Language: C++ 20 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  string s;
  cin >> s;
  ll size = s.size();
  ll b = size, e = 0;
  for (ll i = 0; i < size; i++) {
    if (s[i] == 'A') {
      b = min(b, i);
    }
    if (s[i] == 'Z') {
      e = max(e, i);
    }
  }
  cout << e - b + 1 << endl;
  return 0;
}
