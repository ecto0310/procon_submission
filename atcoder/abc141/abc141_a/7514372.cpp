// Date: Sun, 15 Sep 2019 12:01:17 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  string s;
  cin >> s;
  if (s == "Sunny")
    cout << "Cloudy" << endl;
  else if (s == "Cloudy")
    cout << "Rainy" << endl;
  else
    cout << "Sunny" << endl;
  return 0;
}
