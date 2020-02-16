// Date: Sun, 16 Feb 2020 12:09:15 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  map<string, i64> m;
  for (i64 i = 0; i < n; i++)
  {
    string s;
    cin >> s;
    m[s]++;
  }
  vector<pair<i64, string>> t;
  for (pair<string, i64> i : m)
    t.push_back({i.second, i.first});
  sort(t.begin(), t.end());
  for (pair<i64, string> i : t)
    if (t.back().first == i.first)
      cout << i.second << endl;
  return 0;
}
