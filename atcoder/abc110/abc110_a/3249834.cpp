// Date: Sun, 23 Sep 2018 12:02:14 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int a, b, c;
  cin >> a >> b >> c;
  cout << max({a, b, c}) * 10 + a + b + c - max({a, b, c}) << endl;

  return 0;
}
