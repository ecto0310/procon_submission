// Date: Sat, 06 Jun 2020 09:07:44 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  string s, t;
  cin >> s >> t;
  if (s == t)
  {
    cout << "same" << endl;
    return 0;
  }
  for (char &i : s)
    if ('A' <= i && i <= 'Z')
      i -= 'A' - 'a';
  for (char &i : t)
    if ('A' <= i && i <= 'Z')
      i -= 'A' - 'a';
  if (s == t)
    cout << "case-insensitive" << endl;
  else
    cout << "different" << endl;
  return 0;
}
