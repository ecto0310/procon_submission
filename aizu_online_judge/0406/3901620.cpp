// Date: Tue, 01 Oct 2019 03:59:23 +0000
// Language: C++14
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  i64 ans = 1;
  while (ans * 2 <= n)
    ans *= 2;
  cout << ans << endl;
  return 0;
}
