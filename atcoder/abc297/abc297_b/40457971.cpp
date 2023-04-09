// Date: Sun, 09 Apr 2023 12:06:57 +0000
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
  string S;
  cin >> S;
  bool flag[2] = {};
  i64 index[3] = {-1};
  for (i64 i = 0; i < 8; i++) {
    if (S[i] == 'B') {
      flag[i % 2] = true;
    }
    if (S[i] == 'R') {
      if (index[0] == -1) {
        index[0] = i;
      } else {
        index[1] = i;
      }
    }
    if (S[i] == 'K') {
      index[2] = i;
    }
  }
  if (flag[0] && flag[1] && index[0] < index[2] && index[2] < index[1]) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
