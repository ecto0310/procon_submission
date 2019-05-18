// Date: Sat, 18 May 2019 12:02:32 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 x, y;
  cin >> x >> y;
  if (x % y != 0)
    cout << x << endl;
  else
    cout << -1 << endl;
  return 0;
}
