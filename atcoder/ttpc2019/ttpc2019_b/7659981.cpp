// Date: Sun, 22 Sep 2019 15:59:18 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  for (i64 i = 0; i < n; i++)
  {
    string s;
    cin >> s;
    smatch t;
    if (regex_match(s, t, regex("[a-z]*okyo[a-z]*ech[a-z]*")))
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}
