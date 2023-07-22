// Date: Sat, 22 Jul 2023 12:10:30 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

#ifdef LOCAL
#define cerr cerr << "\033[31m"
#define cout cout << "\033[32m"
#define endl "\033[m" << endl
#endif

int main() {
  ll N;
  string S;
  cin >> N >> S;
  bool ok[3] = {};
  for (ll i = 0; i < N; i++) {
    ok[S[i] - 'A'] = true;
    if (ok[0] && ok[1] && ok[2]) {
      cout << i + 1 << endl;
      return 0;
    }
  }
  return 0;
}
