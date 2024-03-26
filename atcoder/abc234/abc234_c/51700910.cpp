// Date: Tue, 26 Mar 2024 08:32:21 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll K;
  cin >> K;
  vector<ll> a;
  while (0 < K) {
    a.push_back(K % 2);
    K /= 2;
  }
  for (ll i = a.size() - 1; 0 <= i; i--) {
    cout << (a[i] == 0 ? 0 : 2);
  }
  cout << endl;
}
