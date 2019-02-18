// Date: Mon, 18 Feb 2019 15:52:52 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  cin >> N;
  N %= 30;
  string ans = "123456";
  for (int i = 0; i < N; i++)
    swap(ans[i % 5], ans[i % 5 + 1]);
  cout << ans << endl;

  return 0;
}
