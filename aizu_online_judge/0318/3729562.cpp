// Date: Tue, 09 Jul 2019 06:44:11 +0000
// Language: C++14
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, x, y, z;
  cin >> n;
  vector<bool> ga(n), gb(n), gc(n);
  cin >> x;
  for (i64 i = 0; i < x; i++)
  {
    i64 a;
    cin >> a;
    a--;
    ga[a] = true;
  }
  cin >> y;
  for (i64 i = 0; i < y; i++)
  {
    i64 b;
    cin >> b;
    b--;
    gb[b] = true;
  }
  cin >> z;
  for (i64 i = 0; i < z; i++)
  {
    i64 c;
    cin >> c;
    c--;
    gc[c] = true;
  }
  i64 ans = 0;
  for (i64 i = 0; i < n; i++)
    if ((!ga[i] && gc[i]) || (gb[i] && gc[i]))
      ans++;
  cout << ans << endl;
  return 0;
}
