// Date: Sat, 01 Jun 2019 12:02:48 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  string s;
  cin >> s;
  i64 cnt = 0;
  for (i64 i = 0; i < s.size(); i++)
    if (s[i] == 'o')
      cnt++;
  if (8 <= cnt + 15 - s.size())
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
