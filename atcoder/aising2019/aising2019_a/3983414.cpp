// Date: Sat, 12 Jan 2019 12:01:54 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int N, H, W;
  cin >> N >> H >> W;
  cout << (N - H + 1) * (N - W + 1) << endl;

  return 0;
}
