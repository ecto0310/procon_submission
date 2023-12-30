// Date: Sat, 30 Dec 2023 07:50:40 +0000
// Language: C++ 20 (gcc 12.2)
#include <bits/stdc++.h>

using ll = int64_t;
using namespace std;

int main() {
  ll A1, A2, A3;
  cin >> A1 >> A2 >> A3;
  cout << (A1 + A2 + A3 <= 21 ? "win" : "bust") << endl;
  return 0;
}
