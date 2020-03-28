// Date: Sat, 28 Mar 2020 12:00:41 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  string S;
  cin >> S;
  if (S[2] == S[3] && S[4] == S[5])
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
