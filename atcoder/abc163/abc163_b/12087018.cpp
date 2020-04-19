// Date: Sun, 19 Apr 2020 12:05:27 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N, M;
  cin >> N >> M;
  vector<i64> A(M);
  for (i64 i = 0; i < M; i++)
    cin >> A[i];
  i64 sum = 0;
  for (i64 i : A)
    sum += i;
  cout << max(-1LL, N - sum) << endl;
  return 0;
}
