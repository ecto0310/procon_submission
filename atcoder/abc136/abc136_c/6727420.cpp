// Date: Mon, 05 Aug 2019 10:19:08 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<i64> h(n);
  for (i64 i = 0; i < n; i++)
    cin >> h[i];
  for (i64 i = 1; i < n; i++)
  {
    if (h[i - 1] < h[i])
      h[i]--;
    if (h[i] < h[i - 1])
    {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
