// Date: Tue, 30 Apr 2019 04:14:23 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  string s;
  i64 k;
  cin >> s >> k;
  for (i64 i = k; i < k + s.size(); i++)
    cout << s[i % s.size()];
  cout << endl;
  return 0;
}
