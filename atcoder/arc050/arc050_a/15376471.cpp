// Date: Thu, 23 Jul 2020 11:21:37 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  char C, c;
  cin >> C >> c;
  if (c + ('A' - 'a') == C)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
