// Date: Sat, 11 Jul 2020 12:00:49 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 L, R, d;
  cin >> L >> R >> d;
  i64 ans = 0;
  for (i64 i = L; i <= R; i++)
    if (i % d == 0)
      ans++;
  cout << ans << endl;
  return 0;
}
