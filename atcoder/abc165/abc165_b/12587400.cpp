// Date: Sat, 02 May 2020 12:15:00 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 X;
  cin >> X;
  i64 now = 100;
  for (i64 i = 1;; i++)
  {
    now = now * 1.01;
    if (X <= now)
    {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}
