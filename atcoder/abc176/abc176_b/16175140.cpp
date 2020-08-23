// Date: Sun, 23 Aug 2020 07:11:17 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  string N;
  cin >> N;
  i64 cnt = 0;
  for (char i : N)
    cnt += (i - '0');
  if (cnt % 9 == 0)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
