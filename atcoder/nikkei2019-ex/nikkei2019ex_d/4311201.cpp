// Date: Mon, 18 Feb 2019 07:19:48 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int N;
  cin >> N;
  string ans = "1";
  for (int i = 0; i < N - 1; i++)
    ans += "0";
  cout << ans << endl;

  return 0;
}
