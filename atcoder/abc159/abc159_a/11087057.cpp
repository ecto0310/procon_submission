// Date: Sun, 22 Mar 2020 12:04:18 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N, M;
  cin >> N >> M;
  cout << N * (N - 1) / 2 + M * (M - 1) / 2 << endl;
  return 0;
}
