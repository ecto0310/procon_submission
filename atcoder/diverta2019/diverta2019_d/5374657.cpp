// Date: Sun, 12 May 2019 04:48:39 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  i64 ans = 0;
  for (i64 i = 1; i <= sqrt(n); i++)
  {
    i64 p = n / i - 1;
    if (n % i == 0 && i < p)
      ans += p;
  }
  cout << ans << endl;
  return 0;
}
