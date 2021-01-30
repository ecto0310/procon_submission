// Date: Sat, 30 Jan 2021 12:02:23 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 A, B, C;
  cin >> A >> B >> C;
  if (A < B)
    cout << "Aoki" << endl;
  else if (B < A)
    cout << "Takahashi" << endl;
  else if (C == 0)
    cout << "Aoki" << endl;
  else
    cout << "Takahashi" << endl;
  return 0;
}
