// Date: Sat, 16 Feb 2019 05:47:10 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int n;
  string s;
  cin >> n >> s;
  string now = "b";
  int ans = 0;
  for (ans = 0; now.size() < n; ans++)
    if (ans % 3 == 0)
      now = "a" + now + "c";
    else if (ans % 3 == 1)
      now = "c" + now + "a";
    else
      now = "b" + now + "b";
  if (now == s)
    cout << ans << endl;
  else
    cout << -1 << endl;

  return 0;
}
