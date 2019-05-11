// Date: Sat, 11 May 2019 04:44:25 +0000
// Language: C++14
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, c;
  cin >> n >> c;
  vector<i64> p(c);
  for (i64 i = 0; i < c; i++)
    cin >> p[i];
  i64 sum = 0;
  for (i64 i = 0; i < c; i++)
    sum += p[i];
  cout << (sum + n) / (n + 1) << endl;
  return 0;
}
