// Date: Tue, 01 Oct 2019 03:59:51 +0000
// Language: C++14
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<i64> x(n);
  for (i64 i = 0; i < n; i++)
    cin >> x[i];
  sort(x.begin(), x.end());
  i64 p = (x[0] + x[n - 1]) / 2;
  cout << max(abs(p - x[0]), abs(p - x[n - 1])) << endl;
  return 0;
}
