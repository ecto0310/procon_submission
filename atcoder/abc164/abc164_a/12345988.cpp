// Date: Sun, 26 Apr 2020 12:05:16 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 S, W;
  cin >> S >> W;
  if (W < S)
    cout << "safe" << endl;
  else
    cout << "unsafe" << endl;
  return 0;
}
