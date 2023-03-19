// Date: Sun, 19 Mar 2023 12:03:18 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main() {
  i64 H, W;
  cin >> H >> W;
  for (i64 i = 0; i < H; i++) {
    for (i64 j = 0; j < W; j++) {
      i64 A;
      cin >> A;
      cout << ".ABCDEFGHIJKLMNOPQRSTUVWXYZ"[A];
    }
    cout << endl;
  }
  return 0;
}
