// Date: Sat, 20 Apr 2019 14:40:09 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, k;
  string s;
  cin >> n >> s >> k;
  for (i64 i = 0; i < n; i++)
    if (s[i] != s[k - 1])
      s[i] = '*';
  cout << s << endl;

  return 0;
}
