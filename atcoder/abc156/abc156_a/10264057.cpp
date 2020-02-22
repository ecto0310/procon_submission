// Date: Sat, 22 Feb 2020 12:01:34 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 N, R;
  cin >> N >> R;
  cout << R + 100 * max(0LL, 10 - N) << endl;
  return 0;
}
