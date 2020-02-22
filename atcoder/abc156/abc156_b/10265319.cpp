// Date: Sat, 22 Feb 2020 12:02:31 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 N, K;
  cin >> N >> K;
  i64 ans = 0;
  while (0 < N)
  {
    N /= K;
    ans++;
  }
  cout << ans << endl;
  return 0;
}
