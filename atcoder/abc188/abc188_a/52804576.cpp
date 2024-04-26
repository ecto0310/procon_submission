// Date: Fri, 26 Apr 2024 11:33:34 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll X, Y;
  cin >> X >> Y;
  if (abs(X - Y) < 3) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
