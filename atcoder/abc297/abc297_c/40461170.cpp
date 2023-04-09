// Date: Sun, 09 Apr 2023 12:10:17 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define debug(expr) cerr << #expr " = " << (expr) << '\n';
#else
#define debug(...)
#endif

using namespace std;
using i64 = int64_t;

int main() {
  i64 H, W;
  cin >> H >> W;
  vector<string> S(H);
  for (string &i : S) {
    cin >> i;
  }
  for (i64 i = 0; i < H; i++) {
    for (i64 j = 0; j < W - 1; j++) {
      if (S[i].substr(j, 2) == "TT") {
        S[i][j] = 'P';
        S[i][j + 1] = 'C';
      }
    }
  }
  for (string i : S) {
    cout << i << endl;
  }
  return 0;
}
