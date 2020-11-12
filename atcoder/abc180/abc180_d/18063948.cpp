// Date: Thu, 12 Nov 2020 11:39:33 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 X, Y, A, B;
  cin >> X >> Y >> A >> B;
  i64 ans = 0;
  while ((double)A * X <= 2e18 && A * X <= X + B && A * X < Y)
  {
    X *= A;
    ans++;
  }
  cout << ans + (Y - X - 1) / B << endl;
  return 0;
}
