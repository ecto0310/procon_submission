// Date: Sun, 18 Aug 2019 12:02:29 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<i64> a(n);
  for (i64 i = 0; i < n; i++)
    cin >> a[i];
  double tmp = 0;
  for (i64 i = 0; i < n; i++)
    tmp += 1.0 / a[i];
  cout << fixed << setprecision(10) << 1.0 / tmp << endl;
  return 0;
}
