// Date: Tue, 14 Mar 2023 13:57:22 +0000
// Language: GNU C++20 (64)
#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main() {
  i64 t;
  cin >> t;
  while (t--) {
    bool ok = true;
    i64 n;
    string s;
    cin >> n >> s;
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    string t = "meow-";
    bool use[5] = {};
    i64 now = 0;
    for (char i : s) {
      if (i == t[now]) {
        use[now] = true;
        continue;
      }
      if (i == t[now + 1]) {
        use[now + 1] = true;
        now += 1;
        continue;
      }
      ok = false;
    }
    for (i64 i = 0; i < 4; i++) {
      if (!use[i]) {
        ok = false;
      }
    }
    if (ok) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
