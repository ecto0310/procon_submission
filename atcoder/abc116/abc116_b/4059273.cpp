// Date: Sun, 20 Jan 2019 14:32:24 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int s;
  cin >> s;
  int ans = 1;
  map<int, bool> m;
  while (!m[s])
  {
    m[s] = true;
    if (s % 2 == 0)
      s /= 2;
    else
      s = 3 * s + 1;
    ans++;
  }
  cout << ans << endl;

  return 0;
}
