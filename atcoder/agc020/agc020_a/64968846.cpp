// Date: Fri, 18 Apr 2025 10:44:45 +0000
// Language: C++ 20 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll N, A, B;
  cin >> N >> A >> B;
  if ((B - A) % 2 == 0) {
    cout << "Alice" << endl;
  } else {
    cout << "Borys" << endl;
  }
  return 0;
}
