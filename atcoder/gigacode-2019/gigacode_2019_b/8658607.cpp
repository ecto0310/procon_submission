// Date: Tue, 26 Nov 2019 07:24:51 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, x, y, z;
  cin >> n >> x >> y >> z;
  vector<i64> a(n), b(n);
  for (i64 i = 0; i < n; i++)
    cin >> a[i] >> b[i];
  i64 ans = 0;
  for (i64 i = 0; i < n; i++)
    if (x <= a[i] && y <= b[i] && z <= a[i] + b[i])
      ans++;
  cout << ans << endl;
  return 0;
}
