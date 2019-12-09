// Date: Mon, 09 Dec 2019 15:35:16 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<i64> a(n), x[n], y[n];
  for (i64 i = 0; i < n; i++)
  {
    cin >> a[i];
    x[i].resize(a[i]);
    y[i].resize(a[i]);
    for (i64 j = 0; j < a[i]; j++)
      cin >> x[i][j] >> y[i][j];
  }
  i64 ans = 0;
  for (i64 i = 0; i < (1 << n); i++)
  {
    bool ok = true;
    for (i64 j = 0; j < n; j++)
      if (i & (1 << j))
        for (i64 k = 0; k < a[j]; k++)
          if (y[j][k] ^ ((i >> (x[j][k] - 1)) & 1))
            ok = false;
    if (ok)
    {
      i64 cnt = 0;
      for (i64 j = 0; j < n; j++)
        if (i & (1 << j))
          cnt++;
      ans = max(ans, cnt);
    }
  }
  cout << ans << endl;
  return 0;
}
