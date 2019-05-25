// Date: Sat, 25 May 2019 15:16:26 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 a, b;
  cin >> a >> b;
  if (13 <= a)
    cout << b << endl;
  else if (6 <= a)
    cout << b / 2 << endl;
  else
    cout << 0 << endl;
  return 0;
}
