// Date: Sat, 03 Dec 2022 14:50:35 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl '\n'

int main() {
  i64 K;
  cin >> K;
  i64 ans = 1;
  for (i64 i = 2; i * i <= K; i++) {
    i64 cnt = 0;
    while (K % i == 0) {
      K /= i;
      cnt++;
    }
    i64 tmp = 0;
    while (0 < cnt) {
      tmp += i;
      i64 tt = tmp;
      while (tt % i == 0) {
        tt /= i;
        cnt--;
      }
    }
    ans = max(ans, tmp);
  }
  cout << max(ans, K) << endl;

  return 0;
}
