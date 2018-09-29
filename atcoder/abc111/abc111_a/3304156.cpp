// Date: Sat, 29 Sep 2018 15:05:52 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  string n;
  cin >> n;
  for (int i = 0; i < 3; i++)
    cout << (n[i] == '1' ? '9' : '1');
  cout << endl;

  return 0;
}
