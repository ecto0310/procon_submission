// Date: Thu, 20 Dec 2018 12:16:12 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  string n;
  cin >> n;
  cout << ((n[0] == n[1] && n[1] == n[2] || n[1] == n[2] && n[2] == n[3]) ? "Yes" : "No") << endl;

  return 0;
}
