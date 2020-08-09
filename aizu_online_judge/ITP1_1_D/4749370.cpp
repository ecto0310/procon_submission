// Date: Sun, 09 Aug 2020 11:06:19 +0000
// Language: C++14
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 S;
  cin >> S;
  cout << S / 3600 << ":" << S % 3600 / 60 << ":" << S % 60 << endl;
  return 0;
}
