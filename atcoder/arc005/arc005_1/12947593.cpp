// Date: Fri, 08 May 2020 07:01:26 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N;
  cin >> N;
  vector<string> w(N);
  for (i64 i = 0; i < N; i++)
    cin >> w[i];
  i64 ans = 0;
  for (i64 i = 0; i < N; i++)
  {
    for (char &j : w[i])
      if ('A' <= j && j <= 'Z')
        j -= 'A' - 'a';
    if (w[i] == "takahashikun" || w[i] == "takahashikun.")
      ans++;
  }
  cout << ans << endl;
  return 0;
}
