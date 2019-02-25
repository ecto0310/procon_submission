// Date: Mon, 25 Feb 2019 15:00:18 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>

using namespace std;

int main()
{
  string S;
  cin >> S;
  if (4 < stoi(S.substr(5, 2)))
    cout << "TBD" << endl;
  else
    cout << "Heisei" << endl;

  return 0;
}
