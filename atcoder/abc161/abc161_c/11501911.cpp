// Date: Sat, 04 Apr 2020 12:08:13 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N, K;
  cin >> N >> K;
  cout << min(N % K, K - N % K) << endl;
  return 0;
}
