// Date: Wed, 11 Sep 2019 07:12:29 +0000
// Language: C++14
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 x;
  cin >> x;
  string ans[7] = {"thu", "fri", "sat", "sun", "mon", "tue", "wed"};
  cout << ans[x % 7] << endl;
  return 0;
}
