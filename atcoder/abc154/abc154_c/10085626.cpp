// Date: Fri, 14 Feb 2020 06:47:26 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  set<i64> a;
  for (i64 i = 0; i < n; i++)
  {
    i64 t;
    cin >> t;
    a.insert(t);
  }
  if (a.size() == n)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
