// Date: Sat, 16 Jan 2021 12:28:05 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N;
  cin >> N;
  vector<i64> a(N), b(N);
  for (i64 i = 0; i < N; i++)
    cin >> a[i];
  for (i64 i = 0; i < N; i++)
    cin >> b[i];
  i64 ans = 0, am = 0;
  for (i64 i = 0; i < N; i++)
  {
    am = max(am, a[i]);
    ans = max(ans, am * b[i]);
    cout << ans << endl;
  }
  return 0;
}
