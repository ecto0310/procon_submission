// Date: Sun, 12 Apr 2020 12:01:41 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N;
  cin >> N;
  i64 ans = 0;
  for (i64 i = 1; i <= N; i++)
    if (i % 3 != 0 && i % 5 != 0)
      ans += i;
  cout << ans << endl;
  return 0;
}
