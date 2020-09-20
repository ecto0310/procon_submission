// Date: Sun, 20 Sep 2020 03:27:39 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  string S;
  cin >> S;
  if (S[S.size() - 1] == 's')
    cout << S + "es" << endl;
  else
    cout << S + "s" << endl;
  return 0;
}
