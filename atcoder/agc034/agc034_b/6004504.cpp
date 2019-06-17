// Date: Mon, 17 Jun 2019 23:08:09 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  string s;
  cin >> s;
  i64 ans = 0, cnt = 0, size = s.size();
  for (i64 i = 0; i < size - 1; i++)
    if (s[i] == 'B' && s[i + 1] == 'C')
    {
      ans += cnt;
      i++;
    }
    else if (s[i] == 'A')
      cnt++;
    else
      cnt = 0;
  cout << ans << endl;
  return 0;
}
