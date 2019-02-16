// Date: Sat, 16 Feb 2019 14:16:30 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int A, B;
  cin >> A >> B;
  if (B % A == 0)
    cout << A + B << endl;
  else
    cout << B - A << endl;

  return 0;
}
