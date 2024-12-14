// Date: Sat, 14 Dec 2024 12:02:39 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll N;
  string c1, c2, S;
  cin >> N >> c1 >> c2 >> S;
  for (char &i : S) {
    if (i != c1[0]) {
      i = c2[0];
    }
  }
  cout << S << endl;
  return 0;
}
