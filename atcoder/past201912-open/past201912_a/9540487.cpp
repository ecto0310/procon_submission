// Date: Thu, 16 Jan 2020 22:02:04 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  string s;
  cin >> s;
  bool ok = true;
  for (i64 i = 0; i < s.size(); i++)
    if ('a' <= s[i] && s[i] <= 'z')
      ok = false;
  if (ok)
    cout << stoll(s) * 2 << endl;
  else
    cout << "error" << endl;
  return 0;
}
