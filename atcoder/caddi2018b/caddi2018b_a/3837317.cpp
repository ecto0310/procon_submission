// Date: Sat, 22 Dec 2018 12:00:53 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  string s;
  cin >> s;
  int ans = 0;
  for (int i = 0; i < 4; i++)
    if (s[i] == '2')
      ans++;
  cout << ans << endl;

  return 0;
}
