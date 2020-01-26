// Date: Sun, 26 Jan 2020 12:09:40 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 h;
  cin >> h;
  i64 ans = 0, mob = 1;
  while (1 < h)
  {
    ans += mob;
    h /= 2;
    mob *= 2;
  }
  ans += mob;
  cout << ans << endl;
  return 0;
}
