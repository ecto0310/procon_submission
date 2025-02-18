// Date: Tue, 18 Feb 2025 12:06:41 +0000
// Language: C++ 20 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll N;
  cin >> N;
  string S;
  cin >> S;
  for (char &i : S) {
    if (i == 'J') {
      i = 'O';
    } else if (i == 'O') {
      i = 'I';
    } else if (i == 'I') {
      i = 'J';
    }
  }
  cout << S << endl;
  return 0;
}
