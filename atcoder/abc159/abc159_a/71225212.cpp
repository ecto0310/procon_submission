// Date: Tue, 25 Nov 2025 11:14:38 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll N, M;
  cin >> N >> M;
  cout << N * (N - 1) / 2 + M * (M - 1) / 2 << endl;
  return 0;
}
