// Date: Fri, 22 Nov 2024 13:42:54 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll N;
  cin >> N;
  string S;
  cin >> S;
  string t = string(N / 2, '1') + "/" + string(N / 2, '2');
  if (S == t) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
