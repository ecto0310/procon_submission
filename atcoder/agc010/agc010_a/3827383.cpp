// Date: Thu, 20 Dec 2018 09:16:19 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int n;
  cin >> n;
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    if (a % 2 != 0)
      cnt++;
  }
  cout << (cnt % 2 == 0 ? "YES" : "NO") << endl;

  return 0;
}
