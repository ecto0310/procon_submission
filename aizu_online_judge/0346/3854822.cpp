// Date: Mon, 09 Sep 2019 05:08:30 +0000
// Language: C++14
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  vector<i64> e(12);
  for (i64 i = 0; i < 12; i++)
    cin >> e[i];
  sort(e.begin(), e.end());
  bool ok = true;
  for (i64 i = 0; i < 3; i++)
    for (i64 j = 0; j < 4; j++)
      if (e[i * 4] != e[i * 4 + j])
        ok = false;
  if (ok)
    cout << "yes" << endl;
  else
    cout << "no" << endl;
  return 0;
}
