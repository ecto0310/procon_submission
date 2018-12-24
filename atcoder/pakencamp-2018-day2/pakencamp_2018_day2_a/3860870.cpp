// Date: Mon, 24 Dec 2018 04:14:28 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; i++)
  {
    bool ok = true;
    int tmp = i;
    while (tmp)
    {
      if (tmp % 1000 == 123)
        ok = false;
      tmp /= 10;
    }
    if (ok)
      ans++;
  }
  cout << ans << endl;

  return 0;
}
