// Date: Sun, 24 Nov 2019 12:03:51 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  string s;
  cin >> n >> s;
  for (i64 i = 0; i < s.size(); i++)
    s[i] = ((s[i] - 'A') + n) % 26 + 'A';
  cout << s << endl;
  return 0;
}
