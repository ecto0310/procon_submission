// Date: Sun, 09 Jun 2019 14:37:51 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  string s;
  cin >> s;
  i64 cnt[3] = {};
  for (i64 i = 0; i < s.size(); i++)
    cnt[s[i] - 'a']++;
  if (1 < max({cnt[0], cnt[1], cnt[2]}) - min({cnt[0], cnt[1], cnt[2]}))
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
  return 0;
}
