// Date: Sat, 13 Apr 2019 18:45:17 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 a, b;
  cin >> a >> b;
  if (a < b)
    cout << b + max(b - 1, a) << endl;
  else
    cout << a + max(a - 1, b) << endl;
  return 0;
}
