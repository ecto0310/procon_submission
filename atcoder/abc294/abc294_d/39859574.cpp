// Date: Sun, 19 Mar 2023 12:23:40 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main() {
  i64 N, Q;
  cin >> N >> Q;
  vector<bool> go(N + 1);
  i64 next_call = 1, next_recall = 1;
  for (i64 _ = 0; _ < Q; _++) {
    i64 e;
    cin >> e;
    if (e == 1) {
      next_call++;
    } else if (e == 2) {
      i64 p;
      cin >> p;
      go[p] = true;
    } else {
      while (go[next_recall]) {
        next_recall++;
      }
      cout << next_recall << endl;
    }
  }
  return 0;
}
