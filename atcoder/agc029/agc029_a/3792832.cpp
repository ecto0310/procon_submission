// Date: Sat, 15 Dec 2018 12:04:24 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  string s;
  cin >> s;
  long long ans = 0, cnt = 0;
  int size = s.size();
  for (int i = 0; i < size; i++)
    if (s[i] == 'B')
    {
      ans += size - i;
      cnt++;
    }
  cout << ans - cnt * (cnt + 1) / 2 << endl;

  return 0;
}
