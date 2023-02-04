// Date: Sat, 04 Feb 2023 12:07:23 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

struct UnionFind {
  vector<int> data;
  UnionFind(int sz) { data.assign(sz, -1); }
  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return (false);
    if (data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }

  int find(int k) {
    if (data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }

  int size(int k) { return (-data[find(k)]); }
};

int main() {
  i64 N, M;
  cin >> N >> M;
  UnionFind uf(N);
  i64 ans = 0;
  for (i64 i = 0; i < M; i++) {
    i64 A, B;
    cin >> A >> B;
    if (!uf.unite(A - 1, B - 1)) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
