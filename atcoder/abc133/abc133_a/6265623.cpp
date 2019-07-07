// Date: Sun, 07 Jul 2019 12:00:54 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, a, b;
  cin >> n >> a >> b;
  cout << min(n * a, b) << endl;
  return 0;
}
