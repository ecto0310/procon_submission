// Date: Sat, 15 Nov 2025 12:50:39 +0000
// Language: C++23 (GCC 15.2.0)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  vector<string> S(3);
  cin >> S[0] >> S[1] >> S[2];
  sort(S.rbegin(), S.rend());
  cout << S[0] << S[1] << S[2] << endl;
  return 0;
}
