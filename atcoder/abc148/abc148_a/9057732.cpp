// Date: Sun, 22 Dec 2019 12:02:50 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  string a, b;
  cin >> a >> b;
  for (i64 i = 1; i < 4; i++)
  {
    string s = to_string(i);
    if (s != a && s != b)
    {
      cout << s << endl;
      return 0;
    }
  }
  return 0;
}
