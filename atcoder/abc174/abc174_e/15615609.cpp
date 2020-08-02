// Date: Sun, 02 Aug 2020 12:29:30 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N, K;
  cin >> N >> K;
  vector<i64> A(N);
  for (i64 i = 0; i < N; i++)
    cin >> A[i];
  i64 ok = 1e9, ng = 0;
  while (1 < ok - ng)
  {
    i64 mid = (ok + ng) / 2;
    i64 cnt = 0;
    for (i64 i = 0; i < N; i++)
      cnt += A[i] / mid - (A[i] % mid == 0);
    if (K < cnt)
      ng = mid;
    else
      ok = mid;
  }
  cout << ok << endl;
  return 0;
}
