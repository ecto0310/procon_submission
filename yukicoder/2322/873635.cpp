// Date: Sun, 28 May 2023 13:35:22 +0000
// Language: C++17
#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main() {
  string S;
  cin >> S;
  if (S[0] == S[1] && S[1] != S[2]) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
