// Date: Tue, 26 Jan 2021 09:40:54 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N, X;
  string S;
  cin >> N >> X >> S;
  for (i64 i = 0; i < N; i++)
    if (S[i] == 'o')
      X++;
    else
      X = max(0LL, X - 1);
  cout << X << endl;
  return 0;
}
