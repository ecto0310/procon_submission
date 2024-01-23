// Date: Tue, 23 Jan 2024 10:07:32 +0000
// Language: C++ 20 (gcc 12.2)
#include <bits/stdc++.h>

using ll = int64_t;
using namespace std;

int main() {
  ll N;
  cin >> N;
  ll sumX = 0, sumY = 0;
  for (ll i = 0; i < N; i++) {
    ll X, Y;
    cin >> X >> Y;
    sumX += X;
    sumY += Y;
  }
  if (sumX < sumY) {
    cout << "Aoki" << endl;
  } else if (sumY < sumX) {
    cout << "Takahashi" << endl;
  } else {
    cout << "Draw" << endl;
  }
  return 0;
}
