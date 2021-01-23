// Date: Sat, 23 Jan 2021 12:03:05 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N, X;
  cin >> N >> X;
  X *= 100;
  for (i64 i = 0; i < N; i++)
  {
    i64 V, P;
    cin >> V >> P;
    X -= V * P;
    if (X < 0)
    {
      cout << i + 1 << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
