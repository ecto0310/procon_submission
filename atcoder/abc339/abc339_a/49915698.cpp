// Date: Sat, 03 Feb 2024 12:02:52 +0000
// Language: C++ 20 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  string S;
  cin >> S;
  ll last = 0;
  for (ll i = 0; i < S.size(); i++) {
    if (S[i] == '.') {
      last = i;
    }
  }
  cout << S.substr(last + 1, S.size() - last - 1) << endl;
  return 0;
}
