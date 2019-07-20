// Date: Sat, 20 Jul 2019 12:01:54 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, d;
  cin >> n >> d;
  d = d * 2 + 1;
  cout << (n + d - 1) / d << endl;
  return 0;
}
