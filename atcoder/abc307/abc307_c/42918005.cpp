// Date: Sat, 24 Jun 2023 12:57:57 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main() {
  i64 HA, WA;
  cin >> HA >> WA;
  set<pair<i64, i64>> As;
  for (int i = 0; i < HA; i++) {
    string A;
    cin >> A;
    for (int j = 0; j < WA; j++) {
      if (A[j] == '#') {
        As.insert({i, j});
      }
    }
  }
  i64 HB, WB;
  cin >> HB >> WB;
  set<pair<i64, i64>> Bs;
  for (int i = 0; i < HB; i++) {
    string B;
    cin >> B;
    for (int j = 0; j < WB; j++) {
      if (B[j] == '#') {
        Bs.insert({i, j});
      }
    }
  }
  i64 HX, WX;
  cin >> HX >> WX;
  i64 H = max({HA, HB, HX});
  i64 W = max({WA, WB, WX});
  set<pair<i64, i64>> Xs;
  for (int i = 0; i < HX; i++) {
    string X;
    cin >> X;
    for (int j = 0; j < WX; j++) {
      if (X[j] == '#') {
        Xs.insert({H + i, W + j});
      }
    }
  }
  for (i64 iha = 0; iha < H * 3 - HA; iha++) {
    for (i64 iwa = 0; iwa < W * 3 - WA; iwa++) {
      for (i64 ihb = 0; ihb < H * 3 - HB; ihb++) {
        for (i64 iwb = 0; iwb < W * 3 - WB; iwb++) {
          set<pair<i64, i64>> s;
          for (auto [i, j] : As) {
            s.insert({iha + i, iwa + j});
          }
          for (auto [i, j] : Bs) {
            s.insert({ihb + i, iwb + j});
          }
          if (s == Xs) {
            cout << "Yes" << endl;
            return 0;
          }
        }
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
