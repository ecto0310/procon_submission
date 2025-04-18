// Date: Fri, 18 Apr 2025 10:50:30 +0000
// Language: C++ 20 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  string S1, S2;
  cin >> S1 >> S2;
  if (S1 == S2) {
    if (S1 == "sick") {
      cout << 1 << endl;
    } else {
      cout << 4 << endl;
    }
  } else if (S1 == "sick") {
    cout << 2 << endl;
  } else if (S2 == "sick") {
    cout << 3 << endl;
  }
  return 0;
}
