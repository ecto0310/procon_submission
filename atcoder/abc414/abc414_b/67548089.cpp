// Date: Sat, 12 Jul 2025 13:07:09 +0000
// Language: C++ 20 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll N;
  cin >> N;
  string ans;
  for (ll i = 0; i < N; i++) {
    string C;
    ll l;
    cin >> C >> l;
    if (100 < ans.size() + l) {
      cout << "Too Long" << endl;
      return 0;
    }
    ans += string(l, C[0]);
  }
  cout << ans << endl;

  return 0;
}
