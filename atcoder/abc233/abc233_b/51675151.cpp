// Date: Mon, 25 Mar 2024 09:19:34 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll L, R;
  cin >> L >> R;
  string S;
  cin >> S;
  reverse(S.begin() + L - 1, S.begin() + R);
  cout << S << endl;
}
