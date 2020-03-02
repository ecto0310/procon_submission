// Date: Mon, 02 Mar 2020 06:27:51 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 N;
  cin >> N;
  vector<i64> a(N), b(N);
  for (i64 i = 0; i < N; i++)
    cin >> a[i];
  for (i64 i = 0; i < N; i++)
    cin >> b[i];
  i64 ans = 0;
  for (i64 i = 0; i < N; i++)
    if (a[i] < b[i])
      ans += (b[i] - a[i]) / 2;
    else
      ans -= a[i] - b[i];
  if (ans < 0)
    cout << "No" << endl;
  else
    cout << "Yes" << endl;
  return 0;
}
