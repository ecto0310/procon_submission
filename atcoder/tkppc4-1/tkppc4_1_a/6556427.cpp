// Date: Sat, 27 Jul 2019 07:48:30 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, w;
  cin >> n >> w;
  i64 ans = 0;
  for (i64 i = 0; i <= n; i++)
    if (w < (double)n * w / i)
      ans = i;
  cout << ans << endl;
  return 0;
}
