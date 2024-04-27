// Date: Sat, 27 Apr 2024 15:35:26 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  vector<ll> A(9), B(8);
  for (ll &i : A) {
    cin >> i;
  }
  for (ll &i : B) {
    cin >> i;
  }
  ll sumA = 0;
  for (ll i : A) {
    sumA += i;
  }
  ll sumB = 0;
  for (ll i : B) {
    sumB += i;
  }
  cout << sumA - sumB + 1 << endl;
}
