// Date: Sat, 27 Jun 2020 12:01:04 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  string S, T;
  cin >> S >> T;
  i64 ans = 0;
  for (i64 i = 0; i < S.size(); i++)
    if (S[i] != T[i])
      ans++;
  cout << ans << endl;
  return 0;
}
