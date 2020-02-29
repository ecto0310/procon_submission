// Date: Sat, 29 Feb 2020 08:42:55 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 a[3];
  cin >> a[0] >> a[1] >> a[2];
  sort(a, a + 3);
  if (a[1] == 1)
    cout << 1 << endl;
  else
    cout << 2 << endl;
  return 0;
}
