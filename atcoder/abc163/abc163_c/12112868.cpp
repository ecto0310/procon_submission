// Date: Sun, 19 Apr 2020 12:15:28 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N;
  cin >> N;
  vector<i64> A(N - 1);
  for (i64 i = 0; i < N - 1; i++)
    cin >> A[i];
  vector<i64> ans(N);
  for (i64 i : A)
    ans[i - 1]++;
  for (i64 i : ans)
    cout << i << endl;
  return 0;
}
