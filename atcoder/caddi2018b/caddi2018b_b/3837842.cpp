// Date: Sat, 22 Dec 2018 12:02:23 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int n, h, w;
  cin >> n >> h >> w;
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    int a, b;
    cin >> a >> b;
    if (h <= a && w <= b)
      ans++;
  }
  cout << ans << endl;

  return 0;
}
