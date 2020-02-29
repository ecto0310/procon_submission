// Date: Sat, 29 Feb 2020 08:43:14 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, m;
  cin >> n >> m;
  vector<i64> c(n + m);
  for (i64 i = 0; i < n + m; i++)
    cin >> c[i];
  sort(c.begin(), c.end());
  for (i64 i : c)
    cout << i << endl;
  return 0;
}
