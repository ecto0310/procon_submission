// Date: Wed, 11 Sep 2019 07:23:09 +0000
// Language: C++14
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 a, b, n;
  cin >> a >> b >> n;
  for (i64 _ = 0; _ < n; _++)
  {
    i64 s, f;
    cin >> s >> f;
    if (a < f && s < b)
    {
      cout << 1 << endl;
      return 0;
    }
  }
  cout << 0 << endl;
  return 0;
}
