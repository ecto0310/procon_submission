// Date: Mon, 24 Feb 2020 16:27:00 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 N, X;
  cin >> N >> X;
  vector<i64> a(N);
  for (i64 i = 0; i < N; i++)
    cin >> a[i];
  i64 ans = 0;
  i64 m = *max_element(a.begin(), a.end()) - X;
  for (i64 i = 0; i < N; i++)
    if (m <= a[i])
      ans++;
  cout << ans << endl;
  return 0;
}
