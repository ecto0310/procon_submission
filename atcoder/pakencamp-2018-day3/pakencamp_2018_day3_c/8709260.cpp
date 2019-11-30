// Date: Sat, 30 Nov 2019 11:16:38 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 b;
  cin >> b;
  i64 ans = 0;
  for (i64 i = 2; i < b; i++)
  {
    i64 t = i;
    while (t < b)
      t *= 1.5;
    if (t == b)
      ans++;
  }
  cout << ans << endl;
  return 0;
}
