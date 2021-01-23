// Date: Sat, 23 Jan 2021 12:00:45 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  string C;
  cin >> C;
  if (C[0] == C[1] && C[1] == C[2])
    cout << "Won" << endl;
  else
    cout << "Lost" << endl;
  return 0;
}
