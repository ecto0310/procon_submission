// Date: Sat, 18 Nov 2023 13:46:02 +0000
// Language: C++ 20 (gcc 12.2)
#include <bits/stdc++.h>

using ll = int64_t;
using namespace std;

int main() {
  string S;
  cin >> S;
  for (ll i = 0; i < S.size(); i++) {
    cout << S[i] << " \n"[i + 1 == S.size()];
  }
  return 0;
}
