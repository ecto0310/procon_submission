// Date: Sat, 09 May 2020 03:59:27 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  string X, s;
  cin >> X >> s;
  for (char i : s)
    if (X[0] != i)
      cout << i;
  cout << endl;
  return 0;
}
