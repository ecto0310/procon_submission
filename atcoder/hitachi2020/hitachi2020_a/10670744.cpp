// Date: Sun, 08 Mar 2020 12:03:07 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  string S;
  cin >> S;
  for (i64 i = 0; i < S.size(); i++)
    if (i + 1 != S.size() && S.substr(i, 2) == "hi")
      i++;
    else
    {
      cout << "No" << endl;
      return 0;
    }
  cout << "Yes" << endl;
  return 0;
}
