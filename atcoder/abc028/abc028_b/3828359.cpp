// Date: Thu, 20 Dec 2018 12:25:47 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  string s;
  cin >> s;
  map<char, int> cnt;
  for (int i = 0; i < s.size(); i++)
    cnt[s[i]]++;
  cout << cnt['A'] << " " << cnt['B'] << " " << cnt['C'] << " " << cnt['D'] << " " << cnt['E'] << " " << cnt['F'] << endl;

  return 0;
}
