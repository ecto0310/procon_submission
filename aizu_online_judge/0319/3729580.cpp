// Date: Tue, 09 Jul 2019 06:47:33 +0000
// Language: C++14
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<i64> p(n);
  for (i64 i = 0; i < n; i++)
    cin >> p[i];
  i64 ans = 0;
  for (i64 i = 0; i <= 100; i++)
  {
    i64 cnt = 0;
    for (i64 j = 0; j < n; j++)
      if (i <= p[j])
        cnt++;
    if (i <= cnt)
      ans = i;
  }
  cout << ans << endl;
  return 0;
}
