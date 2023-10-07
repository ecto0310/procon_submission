// Date: Sat, 07 Oct 2023 12:40:54 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
  ll N, M;
  cin >> N >> M;
  vector<ll> A(M);
  for (ll &i : A) {
    cin >> i;
  }
  vector<string> S(N);
  for (string &i : S) {
    cin >> i;
  }
  vector<ll> score(N);
  for (ll i = 0; i < N; i++) {
    score[i] = i + 1;
    for (ll j = 0; j < M; j++) {
      if (S[i][j] == 'o') score[i] += A[j];
    }
  }
  ll top = *max_element(score.begin(), score.end());
  for (ll i = 0; i < N; i++) {
    vector<ll> ns;
    for (ll j = 0; j < M; j++) {
      if (S[i][j] == 'x') {
        ns.push_back(A[j]);
      }
    }
    sort(ns.rbegin(), ns.rend());
    ll ans = 0, s = score[i];
    for (ll j : ns) {
      if (top <= s) {
        break;
      }
      s += j;
      ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
