// Date: Tue, 18 Jul 2023 17:37:16 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
  ll H, W;
  cin >> H >> W;
  vector<string> A(H), B(H);
  for (string &i : A) {
    cin >> i;
  }
  for (string &i : B) {
    cin >> i;
  }

  auto check = [=](ll hd, ll wd) {
    for (ll i = 0; i < H; i++) {
      for (ll j = 0; j < W; j++) {
        if (A[(i + hd) % H][(j + wd) % W] != B[i][j]) {
          return false;
        }
      }
    }
    return true;
  };

  for (ll i = 0; i < H; i++) {
    for (ll j = 0; j < W; j++) {
      if (check(i, j)) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
