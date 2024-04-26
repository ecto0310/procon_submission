// Date: Fri, 26 Apr 2024 11:34:38 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll N;
  cin >> N;
  for (ll i = 0; i < N; i++) {
    if (i % 3 == 2) {
      cout << "x";
    } else {
      cout << "o";
    }
  }
  cout << endl;
}
