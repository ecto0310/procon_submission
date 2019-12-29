// Date: Sun, 29 Dec 2019 11:03:15 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 a, b, k;
  cin >> a >> b >> k;
  if (k < a)
    cout << a - k << " " << b << endl;
  else
    cout << 0 << " " << max(0LL, b - (k - a)) << endl;
  return 0;
}
