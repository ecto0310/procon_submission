// Date: Sat, 06 Oct 2018 13:01:31 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  for (int i = m / n; i > 0; i--)
    if (m % i == 0 && m / i >= n)
    {
      cout << i << endl;
      return 0;
    }

  return 0;
}
