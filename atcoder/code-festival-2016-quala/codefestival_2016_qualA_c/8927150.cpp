// Date: Thu, 12 Dec 2019 15:18:49 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  string s;
  i64 k;
  cin >> s >> k;
  i64 len = s.size();
  for (i64 i = 0; i < len; i++)
    if (s[i] != 'a' && 'z' - s[i] + 1 <= k)
    {
      k -= 'z' - s[i] + 1;
      s[i] = 'a';
    }
  k %= 26;
  s[len - 1] = (s[len - 1] - 'a' + k) % 26 + 'a';
  cout << s << endl;
  return 0;
}
