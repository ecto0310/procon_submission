// Date: Tue, 12 Feb 2019 16:30:24 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  string S;
  cin >> S;
  string t = "WBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBW";
  string ans[] = {"Do", "Do", "Re", "Re", "Mi", "Fa", "Fa", "So", "So", "La", "La", "Si"};
  for (int i = 0; i < 12; i++)
    if (S == t.substr(i, 20))
    {
      cout << ans[i] << endl;
      break;
    }

  return 0;
}
