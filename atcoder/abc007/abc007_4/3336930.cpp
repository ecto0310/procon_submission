// Date: Fri, 05 Oct 2018 14:58:43 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

long long solve(long long t)
{
  string s = to_string(t);
  int len = s.size();
  long long dp[20][2][2] = {};
  dp[0][0][0] = 1;
  for (int i = 0; i < len; i++)
  {
    int now = s[i] - '0';
    cerr << now << endl;
    for (int j = 0; j < 2; j++)
      for (int k = 0; k < 2; k++)
        for (int l = 0; l < (k == 0 ? now + 1 : 10); l++)
          dp[i + 1][j || l == 4 || l == 9][k || l < now] += dp[i][j][k];
  }
  return dp[len][1][0] + dp[len][1][1];
}

int main()
{
  long long a, b;
  cin >> a >> b;
  cout << solve(b) - solve(a - 1) << endl;

  return 0;
}
