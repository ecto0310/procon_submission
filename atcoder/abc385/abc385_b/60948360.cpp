// Date: Sat, 21 Dec 2024 12:07:41 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll H, W, X, Y;
  cin >> H >> W >> X >> Y;
  X--;
  Y--;
  vector<string> S(H);
  for (auto &i : S) {
    cin >> i;
  }
  string T;
  cin >> T;
  set<pair<ll, ll>> ans;
  if (S[X][Y] == '@') {
    ans.insert({X, Y});
  }
  for (char i : T) {
    ll nX = X, nY = Y;
    if (i == 'U') {
      nX--;
    } else if (i == 'D') {
      nX++;
    } else if (i == 'L') {
      nY--;
    } else if (i == 'R') {
      nY++;
    }
    if (S[nX][nY] != '#') {
      X = nX;
      Y = nY;
    }
    if (S[X][Y] == '@') {
      ans.insert({X, Y});
    }
  }
  cout << X + 1 << " " << Y + 1 << " " << ans.size() << endl;
  return 0;
}
