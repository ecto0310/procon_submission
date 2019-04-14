// Date: Sun, 14 Apr 2019 11:10:24 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, t;
  cin >> n >> t;
  i64 sum = 0;
  for (i64 i = 0; i < n - 1; i++)
  {
    i64 a;
    cin >> a;
    sum += a;
  }
  cout << (sum + t - 1) / t << endl;
  return 0;
}
