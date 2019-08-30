// Date: Fri, 30 Aug 2019 15:07:13 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<string> s(n);
  for (i64 i = 0; i < n; i++)
  {
    cin >> s[i];
    sort(s[i].begin(), s[i].end());
  }
  map<string, i64> m;
  i64 ans = 0;
  for (i64 i = 0; i < n; i++)
  {
    ans += m[s[i]];
    m[s[i]]++;
  }
  cout << ans << endl;
  return 0;
}
