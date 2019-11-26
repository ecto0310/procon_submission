// Date: Tue, 26 Nov 2019 06:42:29 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  if (n % 2 == 0)
    cout << n / 2 - 1 << endl;
  else
    cout << n / 2 << endl;
  return 0;
}
