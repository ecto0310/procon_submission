// Date: Sun, 09 Jun 2019 14:15:00 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
      i64 a, b, c, d, e;
      cin >> a >> b >> c >> d >> e;
      cout << max(a + d + e, b + c + e) << endl;
      return 0;
}
