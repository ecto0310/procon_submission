// Date: Sat, 21 Dec 2024 12:02:26 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll A, B, C;
  cin >> A >> B >> C;
  ll sum = A + B + C;
  if (min({A, B, C}) + (sum - max({A, B, C}) - min({A, B, C})) ==
          max({A, B, C}) ||
      (A == B && B == C)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
