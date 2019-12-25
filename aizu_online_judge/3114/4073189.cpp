// Date: Wed, 25 Dec 2019 00:30:09 +0000
// Language: C++14
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<i64> a(n);
  for (i64 i = 0; i < n; i++)
    cin >> a[i];
  i64 ans = 0, now = 1e18;
  for (i64 i = 0; i < n; i++)
    if (a[i] < now)
    {
      ans = i + 1;
      now = a[i];
    }
  cout << ans << endl;
  return 0;
}
