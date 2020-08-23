// Date: Sun, 23 Aug 2020 07:10:09 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N, X, T;
  cin >> N >> X >> T;
  cout << (N + X - 1) / X * T << endl;
  return 0;
}
