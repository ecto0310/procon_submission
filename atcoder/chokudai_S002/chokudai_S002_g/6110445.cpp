// Date: Mon, 24 Jun 2019 15:12:40 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  set<pair<i64, i64>> s;
  for (i64 i = 0; i < n; i++)
  {
    i64 a, b;
    cin >> a >> b;
    cout << __gcd(a, b) << endl;
  }
  return 0;
}
