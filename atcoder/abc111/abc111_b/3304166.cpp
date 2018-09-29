// Date: Sat, 29 Sep 2018 15:06:39 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int n;
  cin >> n;
  for (int i = n; i < 1000; i++)
    if (i % 111 == 0)
    {
      cout << i << endl;
      return 0;
    }

  return 0;
}
