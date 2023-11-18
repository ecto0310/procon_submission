// Date: Sat, 18 Nov 2023 14:00:46 +0000
// Language: C++ 20 (gcc 12.2)
#include <bits/stdc++.h>

using ll = int64_t;
using namespace std;

int main() {
  ll N, M;
  cin >> N >> M;
  vector<ll> A(M);
  for (ll &i : A) {
    cin >> i;
    i--;
  }
  vector<set<ll>> t(M + 1);
  vector<ll> count(N);
  ll m = 0;
  for (ll i = 0; i < N; i++) {
    t[0].insert(i);
  }
  for (ll i : A) {
    t[count[i]].erase(i);
    count[i]++;
    t[count[i]].insert(i);
    m = max(m, count[i]);
    cout << *t[m].begin() + 1 << endl;
  }
  return 0;
}
