// Date: Sun, 09 Apr 2023 13:10:47 +0000
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
  i64 N, K;
  cin >> N >> K;
  vector<i64> A(N);
  for (i64 &i : A) {
    cin >> i;
  }
  set<i64> s;
  for (i64 i : A) {
    s.insert(i);
  }
  while (1 < K) {
    i64 t = *s.begin();
    debug(t);
    s.erase(t);
    for (i64 i : A) {
      s.insert(t + i);
    }
    while (K < s.size()) {
      s.erase(*s.rbegin());
    }
    K--;
  }
  cout << *s.begin() << endl;

  return 0;
}
