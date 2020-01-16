// Date: Thu, 16 Jan 2020 22:04:04 +0000
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
  for (i64 i = 1; i < n; i++)
    if (a[i - 1] == a[i])
      cout << "stay" << endl;
    else if (a[i - 1] < a[i])
      cout << "up " << a[i] - a[i - 1] << endl;
    else
      cout << "down " << a[i - 1] - a[i] << endl;
  return 0;
}
