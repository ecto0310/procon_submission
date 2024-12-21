// Date: Sat, 21 Dec 2024 12:57:01 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll N, M, Sx, Sy;
  cin >> N >> M >> Sx >> Sy;
  vector<pair<ll, ll>> h(N);
  for (auto &i : h) {
    cin >> i.first >> i.second;
  }
  vector<pair<char, ll>> m(M);
  for (auto &i : m) {
    cin >> i.first >> i.second;
  }
  map<ll, set<ll>> x, y;
  for (auto i : h) {
    x[i.first].insert(i.second);
    y[i.second].insert(i.first);
  }
  set<pair<ll, ll>> ans;
  for (auto i : m) {
    ll nX = Sx, nY = Sy;
    if (i.first == 'U') {
      nY += i.second;
    } else if (i.first == 'D') {
      nY -= i.second;
    } else if (i.first == 'L') {
      nX -= i.second;
    } else if (i.first == 'R') {
      nX += i.second;
    }
    ll tX = nX, tY = nY;
    if (nX != Sx) {
      if (Sx < nX) {
        swap(Sx, nX);
      }
      for (auto it = y[nY].lower_bound(nX); it != y[nY].end() && *it <= Sx;) {
        ans.insert({*it, nY});
        it = y[nY].erase(it);
      }
    } else {
      if (Sy < nY) {
        swap(Sy, nY);
      }
      for (auto it = x[nX].lower_bound(nY); it != x[nX].end() && *it <= Sy;) {
        ans.insert({nX, *it});
        it = x[nX].erase(it);
      }
    }
    Sx = tX;
    Sy = tY;
  }
  cout << Sx << " " << Sy << " " << ans.size() << endl;
  return 0;
}
