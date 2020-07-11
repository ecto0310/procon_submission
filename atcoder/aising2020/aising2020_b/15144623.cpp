// Date: Sat, 11 Jul 2020 12:02:16 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N;
  cin >> N;
  vector<i64> a(N);
  for (i64 i = 0; i < N; i++)
    cin >> a[i];
  i64 ans = 0;
  for (i64 i = 0; i < N; i++)
    if (i % 2 == 0 && a[i] % 2 == 1)
      ans++;
  cout << ans << endl;
  return 0;
}
