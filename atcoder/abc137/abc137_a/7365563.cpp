// Date: Fri, 06 Sep 2019 13:13:15 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 a, b;
  cin >> a >> b;
  cout << max({a + b, a - b, a * b}) << endl;
  return 0;
}
