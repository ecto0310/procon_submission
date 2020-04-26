// Date: Sun, 26 Apr 2020 12:06:45 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N;
  cin >> N;
  vector<string> S(N);
  for (int i = 0; i < N; i++)
    cin >> S[i];
  set<string> s;
  for (string i : S)
    s.insert(i);
  cout << s.size() << endl;
  return 0;
}
