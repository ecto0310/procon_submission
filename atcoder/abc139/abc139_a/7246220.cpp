// Date: Sun, 01 Sep 2019 12:01:08 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  string s, t;
  cin >> s >> t;
  i64 ans = 0;
  for (i64 i = 0; i < s.size(); i++)
    if (s[i] == t[i])
      ans++;
  cout << ans << endl;
  return 0;
}
