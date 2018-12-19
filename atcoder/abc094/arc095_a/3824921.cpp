// Date: Wed, 19 Dec 2018 16:09:03 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; i++)
    cin >> x[i];
  vector<int> s = x;
  sort(s.begin(), s.end());
  for (int i = 0; i < n; i++)
    if (x[i] < s[(n + 1) / 2])
      cout << s[(n + 1) / 2] << endl;
    else
      cout << s[(n + 1) / 2 - 1] << endl;

  return 0;
}
