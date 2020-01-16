// Date: Thu, 16 Jan 2020 16:32:36 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 MOD = 1e9 + 7;

int main()
{
  i64 n;
  cin >> n;
  vector<string> a(n);
  for (i64 i = 0; i < n; i++)
    cin >> a[i];
  i64 ans = 0;
  for (i64 i = 0; i < n; i++)
  {
    for (i64 j = 0; j < a[i].size(); j++)
    {
      ans *= 10;
      (ans += a[i][j] - '0') %= MOD;
    }
  }
  cout << ans << endl;
  return 0;
}
