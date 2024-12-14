// Date: Sat, 14 Dec 2024 12:11:17 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll p[5];
  for (ll i = 0; i < 5; i++) {
    cin >> p[i];
  }
  string id = "ABCDE";
  vector<pair<ll, string>> s;
  for (ll i = 1; i < (1 << 5); i++) {
    ll t = 0;
    string name;
    for (ll j = 0; j < 5; j++) {
      if ((i >> j) & 1) {
        t += p[j];
        name += id[j];
      }
    }
    s.push_back({t, name});
  }
  sort(s.begin(), s.end(), [](auto const& lhs, auto const& rhs) {
    if (lhs.first != rhs.first) {
      return lhs.first > rhs.first;
    }
    return lhs.second < rhs.second;
  });
  for (auto [sc, name] : s) {
    cout << name << endl;
  }
  return 0;
}
