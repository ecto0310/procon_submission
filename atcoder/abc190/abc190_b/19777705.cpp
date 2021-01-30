// Date: Sat, 30 Jan 2021 12:04:44 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N, S, D;
  cin >> N >> S >> D;
  vector<i64> X(N), Y(N);
  for (i64 i = 0; i < N; i++)
    cin >> X[i] >> Y[i];
  for (i64 i = 0; i < N; i++)
    if (X[i] < S && D < Y[i])
    {
      cout << "Yes" << endl;
      return 0;
    }
  cout << "No" << endl;
  return 0;
}
