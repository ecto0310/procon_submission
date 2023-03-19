// Date: Sun, 19 Mar 2023 12:41:04 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main() {
  i64 L, N1, N2;
  cin >> L >> N1 >> N2;
  vector<i64> u1(N1), l1(N1), u2(N2), l2(N2);
  for (i64 i = 0; i < N1; i++) {
    cin >> u1[i] >> l1[i];
  }
  for (i64 i = 0; i < N2; i++) {
    cin >> u2[i] >> l2[i];
  }
  i64 ans = 0;
  i64 next = 2, diff = l1[0], now1 = 1, now2 = 0;
  while (now1 < N1 || now2 < N2) {
    if (next == 1) {
      if (diff < l1[now1]) {
        next = 2;
        if (u1[now1] == u2[now2 - 1]) {
          ans += diff;
        }
        diff = l1[now1] - diff;
      } else {
        if (u1[now1] == u2[now2 - 1]) {
          ans += l1[now1];
        }
        diff -= l1[now1];
      }
      now1++;
    } else {
      if (diff < l2[now2]) {
        next = 1;
        if (u2[now2] == u1[now1 - 1]) {
          ans += diff;
        }
        diff = l2[now2] - diff;
      } else {
        if (u2[now2] == u1[now1 - 1]) {
          ans += l2[now2];
        }
        diff -= l2[now2];
      }
      now2++;
    }
  }
  cout << ans << endl;
  return 0;
}
