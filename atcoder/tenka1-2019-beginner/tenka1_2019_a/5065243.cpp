// Date: Sat, 20 Apr 2019 14:38:39 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 a, b, c;
  cin >> a >> b >> c;
  if ((a < c && c < b) || (b < c && c < a))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}
