// Date: Sat, 22 Jul 2023 12:24:50 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

#ifdef LOCAL
#define cerr cerr << "\033[31m"
#define cout cout << "\033[32m"
#define endl "\033[m" << endl
#endif

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  for (ll i = 0; i < N; i++) {
    cin >> A[i];
    A[i]--;
  }
  vector<bool> use(N);
  queue<ll> ans;
  ans.push(0);
  use[0] = true;
  ll now = A[0];
  while (!use[now]) {
    ans.push(now);
    use[now] = true;
    now = A[now];
  }
  while (ans.front() != now) {
    ans.pop();
  }
  ll M = ans.size();
  cout << M << endl;
  for (ll j = 0; j < M; j++) {
    cout << ans.front() + 1 << " ";
    ans.pop();
  }
  cout << endl;
  return 0;
}
