// Date: Thu, 16 Jan 2020 16:28:31 +0000
// Language: C++14 (GCC 5.4.1)
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
  i64 ans = 0, m = 0;
  for (i64 i = 0; i < n; i++)
  {
    if (m < a[i])
      ans++;
    m = max(m, a[i]);
  }
  cout << ans << endl;
  return 0;
}
