// Date: Thu, 16 Jan 2020 21:56:01 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  i64 ans = 1, tmp = 1;
  for (i64 i = 0; i < n; i++)
  {
    tmp *= 5;
    ans += tmp;
  }
  cout << ans << endl;
  return 0;
}
