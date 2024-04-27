// Date: Sat, 27 Apr 2024 15:37:36 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll N;
  cin >> N;
  vector<string> A(N), B(N);
  for (string &i : A) {
    cin >> i;
  }
  for (string &i : B) {
    cin >> i;
  }
  for (ll i = 0; i < N; i++) {
    for (ll j = 0; j < N; j++) {
      if (A[i][j] != B[i][j]) {
        cout << i + 1 << " " << j + 1 << endl;
        return 0;
      }
    }
  }
  return 0;
}
