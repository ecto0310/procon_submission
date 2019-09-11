// Date: Wed, 11 Sep 2019 07:24:09 +0000
// Language: C++14
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 x, y;
  cin >> x >> y;
  cout << x + y - __gcd(x, y) + 1 << endl;
  return 0;
}
