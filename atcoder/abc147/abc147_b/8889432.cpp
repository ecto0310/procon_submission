// Date: Mon, 09 Dec 2019 15:21:46 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  string s;
  cin >> s;
  i64 ans = 0;
  for (i64 i = 0; i < s.size() / 2; i++)
    if (s[i] != s[s.size() - i - 1])
      ans++;
  cout << ans << endl;
  return 0;
}
