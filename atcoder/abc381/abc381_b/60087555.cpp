// Date: Fri, 22 Nov 2024 13:46:05 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  string S;
  cin >> S;
  vector<ll> c(26);
  for (ll i = 0; i < S.size(); i += 2) {
    if (S[i] != S[i + 1]) {
      cout << "No" << endl;
      return 0;
    }
    if (c[S[i] - 'a'] != 0) {
      cout << "No" << endl;
      return 0;
    }
    c[S[i] - 'a']++;
  }
  cout << "Yes" << endl;
  return 0;
}
