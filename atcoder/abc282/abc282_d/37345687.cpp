// Date: Sat, 17 Dec 2022 12:47:03 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
  i64 N, V;
  cin >> N >> V;
  vector<i64> e[N];
  for (i64 i = 0; i < V; i++) {
    i64 u, v;
    cin >> u >> v;
    u--;
    v--;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  vector<i64> c(N);
  i64 ans = 0, tN = N;
  for (i64 i = 0; i < N; i++) {
    if (c[i] != 0) {
      continue;
    }
    vector<i64> cnt(2);
    queue<i64> que;
    int size = 0, edge = 0;
    c[i] = 1;
    cnt[0] = 1;
    que.push(i);
    while (0 < que.size()) {
      i64 p = que.front();
      que.pop();
      size++;
      edge += e[p].size();
      for (i64 j : e[p]) {
        if (c[j] == 0) {
          c[j] = 3 - c[p];
          cnt[c[j] - 1]++;
          que.push(j);
        } else if (c[j] != 3 - c[p]) {
          cout << 0 << endl;
          return 0;
        }
      }
    }
    ans += cnt[0] * cnt[1] - edge / 2 + (tN - size) * size;
    tN -= size;
  }
  cout << ans << endl;
  return 0;
}
