// Date: Sat, 08 Sep 2018 12:01:25 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int a, b;
  cin >> a >> b;
  if (a * b % 2 == 0)
    cout << "No" << endl;
  else
    cout << "Yes" << endl;

  return 0;
}
