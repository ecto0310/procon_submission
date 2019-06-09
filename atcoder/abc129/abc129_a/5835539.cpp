// Date: Sun, 09 Jun 2019 12:02:21 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 p, q, r;
  cin >> p >> q >> r;
  cout << p + q + r - max({p, q, r}) << endl;
  return 0;
}
