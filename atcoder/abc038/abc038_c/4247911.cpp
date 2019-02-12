// Date: Tue, 12 Feb 2019 16:48:43 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++)
    cin >> a[i];
  long long ans = 0;
  for (int i = 0, r = 0; i < N; i++)
  {
    if (r < i)
      r = i;
    while (r < N - 1 && a[r] < a[r + 1])
      r++;
    ans += r - i + 1;
  }
  cout << ans << endl;

  return 0;
}
