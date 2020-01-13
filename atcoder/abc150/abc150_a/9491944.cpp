// Date: Mon, 13 Jan 2020 06:08:32 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 k, x;
  cin >> k >> x;
  if (x <= k * 500)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
