// Date: Thu, 20 Dec 2018 12:17:33 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << ((double)b / a > (double)d / c ? "TAKAHASHI" : (double)b / a == (double)d / c ? "DRAW" : "AOKI") << endl;

  return 0;
}
