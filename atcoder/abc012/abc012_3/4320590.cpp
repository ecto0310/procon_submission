// Date: Tue, 19 Feb 2019 06:51:55 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int N;
  cin >> N;
  for (int i = 1; i < 10; i++)
    for (int j = 1; j < 10; j++)
      if (N + i * j == 2025)
        cout << i << " x " << j << endl;

  return 0;
}
