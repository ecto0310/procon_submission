// Date: Tue, 26 Mar 2024 08:24:09 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll N, K;
  cin >> N >> K;
  vector<pair<ll, ll>> ab(N);
  ll sum = 0;
  for (ll i = 0; i < N; i++) {
    cin >> ab[i].first >> ab[i].second;
    sum += ab[i].second;
  }
  sort(ab.begin(), ab.end());
  if (sum <= K) {
    cout << 1 << endl;
    return 0;
  }
  for (ll i = 0; i < N; i++) {
    if (sum <= K) {
      cout << ab[i - 1].first + 1 << endl;
      return 0;
    }
    sum -= ab[i].second;
  }
  cout << ab[N - 1].first + 1 << endl;
}
