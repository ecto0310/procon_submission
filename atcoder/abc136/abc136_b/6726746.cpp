// Date: Mon, 05 Aug 2019 09:20:36 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  i64 ans = 0;
  for (i64 i = 1; i <= n; i++)
    if (to_string(i).size() % 2 == 1)
      ans++;
  cout << ans << endl;
  return 0;
}
