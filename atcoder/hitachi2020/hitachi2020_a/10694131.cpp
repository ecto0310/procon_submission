// Date: Sun, 08 Mar 2020 15:53:13 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  string S;
  cin >> S;
  if (regex_match(S, regex("(hi)+")))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
