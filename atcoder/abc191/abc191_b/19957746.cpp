// Date: Sat, 06 Feb 2021 12:04:21 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N, X;
  cin >> N >> X;
  vector<i64> A(N);
  for (i64 i = 0; i < N; i++)
    cin >> A[i];
  for (i64 i = 0; i < N; i++)
    if (A[i] != X)
      cout << A[i] << " ";
  cout << endl;
  return 0;
}
