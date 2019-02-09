// Date: Sat, 09 Feb 2019 19:56:52 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int N, K;
  cin >> N >> K;
  cout << (K * 2 - 1 <= N ? "YES" : "NO") << endl;

  return 0;
}
