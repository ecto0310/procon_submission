// Date: Mon, 17 Dec 2018 14:56:02 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  long long sum = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    sum += a[i];
  }
  long long tmp = 0, ans = 1e16;
  for (int i = 0; i < n - 1; i++)
  {
    tmp += a[i];
    sum -= a[i];
    ans = min(ans, abs(tmp - sum));
  }
  cout << ans << endl;

  return 0;
}
