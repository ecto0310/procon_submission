// Date: Sat, 29 Feb 2020 08:44:22 +0000
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
  i64 ans = 0;
  for (i64 i = 0; i < n; i++)
  {
    i64 j = i + 1;
    for (; j < n; j++)
      if (a[j] < a[j - 1])
        break;
    ans = max(ans, j - i);
  }
  cout << ans << endl;
  return 0;
}
