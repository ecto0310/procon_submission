// Date: Sat, 27 May 2023 12:04:53 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main() {
  i64 N;
  string S, T;
  cin >> N >> S >> T;
  for (i64 i = 0; i < N; i++) {
    if (!(S[i] == T[i] || (S[i] == '1' && T[i] == 'l') ||
          (S[i] == 'l' && T[i] == '1') | (S[i] == '0' && T[i] == 'o') ||
          (S[i] == 'o' && T[i] == '0'))) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
