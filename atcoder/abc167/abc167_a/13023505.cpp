// Date: Sun, 10 May 2020 12:02:19 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  string S, T;
  cin >> S >> T;
  if (S == T.substr(0, T.size() - 1))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
