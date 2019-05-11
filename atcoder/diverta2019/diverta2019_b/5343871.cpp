// Date: Sat, 11 May 2019 12:18:42 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 r, g, b, n;
  cin >> r >> g >> b >> n;
  i64 ans = 0;
  for (i64 i = 0; i <= 3000; i++)
    for (i64 j = 0; j <= 3000; j++)
      if (0 <= n - r * i - g * j && (n - r * i - g * j) % b == 0)
        ans++;
  cout << ans << endl;
  return 0;
}
