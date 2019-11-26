// Date: Tue, 26 Nov 2019 07:34:36 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 d;
  cin >> d;
  vector<i64> a(d), b(d);
  for (i64 i = 0; i < d; i++)
    cin >> a[i];
  for (i64 i = 0; i < d; i++)
    cin >> b[i];
  i64 ans = 1e18, sum = 0;
  for (i64 i = 0; i < d; i++)
  {
    sum += a[i];
    if (b[i] <= sum)
      ans = min(ans, b[i]);
  }
  if (ans == 1e18)
    cout << -1 << endl;
  else
    cout << ans << endl;
  return 0;
}
