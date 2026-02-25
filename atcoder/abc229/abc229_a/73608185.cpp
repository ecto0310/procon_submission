// Date: Wed, 25 Feb 2026 10:47:25 +0000
// Language: C++23 (GCC 15.2.0)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  string S[2];
  cin >> S[0] >> S[1];
  if ((S[0] == "#." && S[1] == ".#") || (S[0] == ".#" && S[1] == "#.")) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
  return 0;
}
