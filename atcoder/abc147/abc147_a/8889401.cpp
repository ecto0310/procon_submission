// Date: Mon, 09 Dec 2019 15:19:43 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 a1, a2, a3;
  cin >> a1 >> a2 >> a3;
  if (22 <= a1 + a2 + a3)
    cout << "bust" << endl;
  else
    cout << "win" << endl;
  return 0;
}
