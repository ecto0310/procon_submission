// Date: Sat, 07 Jun 2025 12:01:39 +0000
// Language: C++ 20 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll N;
  string T, A;
  cin >> N >> T >> A;
  for (ll i = 0; i < N; i++) {
    if (T[i] == 'o' && A[i] == 'o') {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
