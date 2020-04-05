// Date: Sun, 05 Apr 2020 12:01:07 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 S, L, R;
  cin >> S >> L >> R;
  cout << max(L, min(S, R)) << endl;
  return 0;
}
