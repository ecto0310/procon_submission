// Date: Sun, 22 Sep 2019 15:38:30 +0000
// Language: C++14
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  set<vector<i64>> s;
  for (i64 i = 0; i < n; i++)
  {
    vector<i64> a(3);
    cin >> a[0] >> a[1] >> a[2];
    sort(a.begin(), a.end());
    s.insert(a);
  }
  cout << n - s.size() << endl;
  return 0;
}
