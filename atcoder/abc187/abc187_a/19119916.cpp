// Date: Sat, 02 Jan 2021 12:02:36 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 A, B;
  cin >> A >> B;
  i64 cntA = 0, cntB = 0;
  while (A || B)
  {
    cntA += A % 10;
    A /= 10;
    cntB += B % 10;
    B /= 10;
  }
  cout << max(cntA, cntB) << endl;
  return 0;
}
