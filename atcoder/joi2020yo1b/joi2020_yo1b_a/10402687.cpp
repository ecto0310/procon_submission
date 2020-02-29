// Date: Sat, 29 Feb 2020 08:43:29 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 a, b, c;
  cin >> a >> b >> c;
  cout << a + b + c - min({a, b, c}) << endl;
}
