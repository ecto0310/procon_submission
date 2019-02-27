// Date: Wed, 27 Feb 2019 15:50:37 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>

using namespace std;

int main()
{
  string S;
  cin >> S;
  string T;
  for (int i = 0; i < S.size(); i++)
  {
    string tmp = S + T;
    reverse(tmp.begin(), tmp.end());
    if (S + T == tmp)
    {
      cout << i << endl;
      return 0;
    }
    T = S[i] + T;
  }

  return 0;
}
