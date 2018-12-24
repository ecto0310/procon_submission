// Date: Mon, 24 Dec 2018 04:17:31 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int n, d;
  cin >> n >> d;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a.begin(), a.end(), greater<int>());
  int ans = 0;
  for (int i = d - 1; i < n; i += d)
    ans += a[i];
  cout << ans << endl;

  return 0;
}
