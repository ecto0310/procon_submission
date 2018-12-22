// Date: Sat, 22 Dec 2018 12:10:39 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  long long n, p;
  cin >> n >> p;
  unordered_map<long long, long long> m;
  long long now = 2;
  while (now * now <= p)
    if (p % now == 0)
    {
      m[now]++;
      p /= now;
    }
    else
      now++;
  m[p]++;
  long long ans = 1;
  for (pair<long long, long long> t : m)
    for (int i = 0; i < t.second / n; i++)
      ans *= t.first;
  cout << ans << endl;

  return 0;
}
