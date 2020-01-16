// Date: Thu, 16 Jan 2020 16:19:59 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<i64> a(n);
  for (i64 i = 0; i < n; i++)
    cin >> a[i];
  for (i64 i = 0; i < n; i++)
    if (a[i] == 1)
    {
      cout << i + 1 << endl;
      return 0;
    }
  return 0;
}
