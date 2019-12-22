// Date: Sun, 22 Dec 2019 12:04:59 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 a, b;
  cin >> a >> b;
  cout << a / __gcd(a, b) * b << endl;
  return 0;
}
