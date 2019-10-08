// Date: Tue, 08 Oct 2019 16:08:02 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<i64> ans(n);
  for (i64 i = 0; i < n; i++)
  {
    i64 a;
    cin >> a;
    ans[a - 1] = i + 1;
  }
  for (i64 i = 0; i < n; i++)
    cout << ans[i] << (i + 1 == n ? "\n" : " ");
  return 0;
}
