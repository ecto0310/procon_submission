// Date: Sun, 19 Jan 2020 11:51:49 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 a, b;
  cin >> a >> b;
  for (i64 i = 0; i < max(a, b); i++)
    cout << min(a, b);
  cout << endl;
  return 0;
}
