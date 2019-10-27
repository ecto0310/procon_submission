// Date: Sun, 27 Oct 2019 13:40:47 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 a, b;
  cin >> a >> b;
  if (a < 10 && b < 10)
    cout << a * b << endl;
  else
    cout << -1 << endl;
  return 0;
}
