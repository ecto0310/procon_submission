// Date: Fri, 19 Jan 2024 13:41:57 +0000
// Language: C++ 20 (gcc 12.2)
#include <bits/stdc++.h>

using ll = int64_t;
using namespace std;

int main() {
  ll A, B, C;
  cin >> A >> B >> C;
  auto rank = [&](ll num) -> ll {
    if (max({A, B, C}) == num) {
      return 1;
    } else if (min({A, B, C}) == num) {
      return 3;
    }
    return 2;
  };
  cout << rank(A) << endl;
  cout << rank(B) << endl;
  cout << rank(C) << endl;
  return 0;
}
