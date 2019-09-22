// Date: Sun, 22 Sep 2019 15:52:44 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 a, b, t;
  cin >> a >> b >> t;
  cout << (t - b + (b - a) - 1) / (b - a) * (b - a) + b << endl;
  return 0;
}
