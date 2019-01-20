// Date: Sun, 20 Jan 2019 14:36:49 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> h(N);
  for (int i = 0; i < N; i++)
    cin >> h[i];
  int ans = 0, t = 0;
  for (int i = 0; i < N; i++)
    if (t <= h[i])
      t = h[i];
    else
    {
      ans += t - h[i];
      t = h[i];
    }
  cout << ans + t << endl;

  return 0;
}
