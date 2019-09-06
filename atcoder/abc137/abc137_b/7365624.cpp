// Date: Fri, 06 Sep 2019 13:17:05 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 k, x;
  cin >> k >> x;
  for (i64 i = x - k + 1; i < k + x; i++)
    cout << i << (i + 1 == k + x ? "\n" : " ");
  return 0;
}
