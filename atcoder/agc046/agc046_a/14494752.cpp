// Date: Sat, 20 Jun 2020 12:02:04 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 X;
  cin >> X;
  cout << X / gcd(X, 360) * 360 / X << endl;
  return 0;
}
