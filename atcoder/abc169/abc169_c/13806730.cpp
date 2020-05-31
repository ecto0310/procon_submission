// Date: Sun, 31 May 2020 12:14:32 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 A;
  string B;
  cin >> A >> B;
  cout << A * stoi(B.substr(0, 1)) + A * stoi(B.substr(2, 2)) / 100 << endl;
  return 0;
}
