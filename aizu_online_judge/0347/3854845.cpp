// Date: Mon, 09 Sep 2019 05:23:17 +0000
// Language: C++14
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<i64> a(n);
  for (i64 i = 0; i < n; i++)
    cin >> a[i];
  sort(a.begin(), a.end());
  double ans = 0;
  for (i64 i = 0; i < n; i++)
    for (i64 j = i + 1; j < n; j++)
    {
      i64 k = n - 1;
      while (k == i || k == j)
        k--;
      i64 l = k - 1;
      while (l == i || l == j)
        l--;
      ans = max(ans, (double)(a[k] + a[l]) / (a[j] - a[i]));
    }
  cout << fixed << setprecision(6) << ans << endl;
  return 0;
}
