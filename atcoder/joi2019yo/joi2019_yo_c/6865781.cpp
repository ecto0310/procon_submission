// Date: Mon, 12 Aug 2019 08:49:37 +0000
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
  i64 ans = 0;
  for (i64 i = 0; i < n - 1; i++)
    if (s[i] != s[i + 1])
    {
      ans++;
      i++;
    }
  cout << ans << endl;
  return 0;
}
