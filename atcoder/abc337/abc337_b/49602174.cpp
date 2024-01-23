// Date: Tue, 23 Jan 2024 10:08:54 +0000
// Language: C++ 20 (gcc 12.2)
#include <bits/stdc++.h>

using ll = int64_t;
using namespace std;

int main() {
  string S;
  cin >> S;
  ll N = S.size();
  for (ll i = 0; i < N - 1; i++) {
    if (S[i + 1] < S[i]) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
