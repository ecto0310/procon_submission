// Date: Thu, 23 Jul 2020 11:18:23 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 H, W;
  cin >> H >> W;
  cout << H * (W - 1) + W * (H - 1) << endl;
  return 0;
}
