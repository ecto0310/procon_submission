// Date: Sat, 06 Feb 2021 12:02:37 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 V, S, T, D;
  cin >> V >> T >> S >> D;
  if (V * T <= D && D <= V * S)
    cout << "No" << endl;
  else
    cout << "Yes" << endl;
  return 0;
}
