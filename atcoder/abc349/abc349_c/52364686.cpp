// Date: Sat, 13 Apr 2024 16:27:59 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  string S, T;
  cin >> S >> T;
  transform(S.begin(), S.end(), S.begin(), ::toupper);
  transform(T.begin(), T.end(), T.begin(), ::toupper);
  ll now = 0;
  for (char i : S) {
    if (now < 3 && i == T[now]) {
      now++;
    }
  }
  if ((T[2] == 'X' && 2 <= now) || (3 == now)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
