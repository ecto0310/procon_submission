// Date: Sat, 19 Oct 2019 12:04:29 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  string s;
  cin >> n >> s;
  i64 ans = 1;
  for (i64 i = 1; i < n; i++)
    if (s[i] != s[i - 1])
      ans++;
  cout << ans << endl;
  return 0;
}
