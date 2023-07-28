// Date: Fri, 28 Jul 2023 12:11:19 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

#include <atcoder/dsu>

using namespace std;
using ll = int64_t;

#ifdef LOCAL
#define cerr cerr << "\033[31m"
#define cout cout << "\033[32m"
#define endl "\033[m" << endl
#endif

struct Edge {
  ll to;
};

int main() {
  ll N, M;
  cin >> N >> M;
  vector<Edge> edges[N];
  for (ll i = 0; i < M; i++) {
    ll A, B;
    cin >> A >> B;
    A--;
    B--;
    edges[A].push_back({B});
  }
  ll ans = 0;
  for (ll i = 0; i < N; i++) {
    vector<bool> vis(N);
    queue<ll> que;
    vis[i] = true;
    ans++;
    que.push(i);
    while (!que.empty()) {
      ll p = que.front();
      que.pop();
      for (Edge j : edges[p]) {
        if (!vis[j.to]) {
          ans++;
          vis[j.to] = true;
          que.push(j.to);
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
