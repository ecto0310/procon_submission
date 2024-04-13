// Date: Sat, 13 Apr 2024 16:41:12 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll L, R;
  cin >> L >> R;
  vector<pair<ll, ll>> ans;
  ll i = 0;
  while (L < R) {
    if ((L >> i) & 1) {
      ans.push_back({L, L + (1LL << i)});
      L += (1LL << i);
    }
    if ((R >> i) & 1) {
      ans.push_back({R - (1LL << i), R});
      R -= (1LL << i);
    }
    i++;
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << endl;
  for (auto [l, r] : ans) {
    cout << l << " " << r << endl;
  }
}
