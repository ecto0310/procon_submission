// Date: Sun, 16 Feb 2020 12:01:43 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 a, b, c;
  cin >> a >> b >> c;
  if ((a == b && b != c) || (b == c && a != c) || (a == c && a != b))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
