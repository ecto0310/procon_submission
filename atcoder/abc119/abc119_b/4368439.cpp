// Date: Sun, 24 Feb 2019 12:05:48 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  cin >> N;
  double ans = 0;
  for (int i = 0; i < N; i++)
  {
    double x;
    string v;
    cin >> x >> v;
    if (v == "JPY")
      ans += x;
    else
      ans += x * 380000;
  }
  cout << fixed << setprecision(8) << ans << endl;

  return 0;
}
