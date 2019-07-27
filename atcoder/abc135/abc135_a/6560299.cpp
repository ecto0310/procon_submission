// Date: Sat, 27 Jul 2019 12:01:20 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 a, b;
  cin >> a >> b;
  if (abs(a - b) % 2 == 0)
    cout << (a + b) / 2 << endl;
  else
    cout << "IMPOSSIBLE" << endl;
  return 0;
}
