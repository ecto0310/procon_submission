// Date: Mon, 17 Dec 2018 15:39:30 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int n, t;
  cin >> n >> t;
  vector<int> tt(n);
  for (int i = 0; i < n; i++)
    cin >> tt[i];
  int ans = t;
  for (int i = 0; i < n - 1; i++)
    ans += min(t, tt[i + 1] - tt[i]);
  cout << ans << endl;

  return 0;
}
