// Date: Sun, 21 Jun 2020 12:01:03 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  string a;
  cin >> a;
  if ('a' <= a[0] && a[0] <= 'z')
    cout << "a" << endl;
  else
    cout << "A" << endl;
  return 0;
}
