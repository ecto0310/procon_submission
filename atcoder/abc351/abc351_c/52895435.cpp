// Date: Sat, 27 Apr 2024 15:44:19 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  for (ll &i : A) {
    cin >> i;
  }
  vector<ll> l;
  for (ll i : A) {
    l.push_back(i);
    ll s = l.size();
    while (2 <= s && l[s - 1] == l[s - 2]) {
      l.pop_back();
      s--;
      l[s - 1]++;
    }
  }
  cout << l.size() << endl;
  return 0;
}
