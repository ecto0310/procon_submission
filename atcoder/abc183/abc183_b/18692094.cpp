// Date: Sat, 12 Dec 2020 03:35:02 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 Sx, Sy, Gx, Gy;
  cin >> Sx >> Sy >> Gx >> Gy;
  cout << fixed << setprecision(7) << (double)Sy / (Sy + Gy) * (Gx - Sx) + Sx << endl;
  return 0;
}
