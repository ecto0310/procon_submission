// Date: Sun, 28 May 2023 14:30:44 +0000
// Language: C++17
#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

struct Edge {
  vector<i64> to;
  i64 level, nlevel = -1;
};

int main() {
  i64 N;
  cin >> N;
  vector<Edge> edge(N + 1);
  edge[1] = {{}, 0, 0};
  for (i64 i = 2; i <= N; i++) {
    i64 L, A;
    cin >> L >> A;
    edge[A].to.push_back(i);
    edge[i].level = L;
  }
  vector<i64> level;
  queue<i64> que;
  que.push(1);
  while (que.size()) {
    i64 p = que.front();
    que.pop();
    level.push_back(edge[p].nlevel);
    for (i64 i : edge[p].to) {
      edge[i].nlevel = max(edge[i].level, edge[p].nlevel);
      que.push(i);
    }
  }
  sort(level.begin(), level.end());
  i64 Q;
  cin >> Q;
  for (i64 _ = 0; _ < Q; _++) {
    i64 t;
    cin >> t;
    if (t == 1) {
      i64 x;
      cin >> x;
      cout << upper_bound(level.begin(), level.end(), x) - level.begin()
           << endl;
    } else if (t == 2) {
      i64 y;
      cin >> y;
      cout << edge[y].nlevel << endl;
    }
  }
  return 0;
}
