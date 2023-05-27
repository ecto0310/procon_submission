// Date: Sat, 27 May 2023 13:06:42 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main() {
  i64 N;
  cin >> N;
  vector<i64> e[N];
  for (i64 i = 0; i < N - 1; i++) {
    i64 u, v;
    cin >> u >> v;
    u--;
    v--;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  queue<i64> que;
  for (i64 i = 0; i < N; i++) {
    if (e[i].size() == 1) {
      que.push(e[i][0]);
      break;
    }
  }
  vector<bool> use(N);
  vector<i64> ans;
  while (que.size()) {
    i64 t = que.front();
    que.pop();
    if (use[t]) {
      continue;
    }
    use[t] = true;
    for (i64 i : e[t]) {
      if (e[i].size() == 2) {
        i64 next = e[i][0] + e[i][1] - t;
        i64 center = e[next][0] + e[next][1] - i;
        if (!use[center]) {
          que.push(center);
        }
      }
    }
    ans.push_back(e[t].size());
  }
  sort(ans.begin(), ans.end());
  i64 size = ans.size();
  for (i64 i = 0; i < size; i++) {
    cout << ans[i] << (i + 1 == size ? "\n" : " ");
  }
}
