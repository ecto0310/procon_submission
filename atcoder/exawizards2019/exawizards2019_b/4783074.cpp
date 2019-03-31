// Date: Sun, 31 Mar 2019 06:00:52 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int n;
  string s;
  cin >> n >> s;
  int cntR = 0, cntB = 0;
  for (int i = 0; i < n; i++)
    if (s[i] == 'R')
      cntR++;
    else
      cntB++;
  if (cntB < cntR)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}
