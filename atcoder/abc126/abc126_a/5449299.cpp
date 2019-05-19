// Date: Sun, 19 May 2019 12:03:20 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, k;
  string s;
  cin >> n >> k >> s;
  s[k - 1] = s[k - 1] - 'A' + 'a';
  cout << s << endl;
  return 0;
}
