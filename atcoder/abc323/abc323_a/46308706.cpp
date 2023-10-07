// Date: Sat, 07 Oct 2023 12:25:19 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
  string S;
  cin >> S;
  for (int i = 1; i < 16; i += 2) {
    if (S[i] == '1') {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
