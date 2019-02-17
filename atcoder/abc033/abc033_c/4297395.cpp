// Date: Sun, 17 Feb 2019 03:13:04 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  string S;
  cin >> S;
  S += "+";
  int ans = 0;
  bool zero = false;
  for (int i = 0; i < S.size(); i++)
    if (S[i] == '0')
      zero = true;
    else if (S[i] == '+')
    {
      if (!zero)
        ans++;
      zero = false;
    }
  cout << ans << endl;

  return 0;
}
