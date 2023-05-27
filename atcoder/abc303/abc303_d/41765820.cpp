// Date: Sat, 27 May 2023 13:16:56 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main() {
  i64 X, Y, Z;
  cin >> X >> Y >> Z;
  string S;
  cin >> S;
  vector<vector<i64>> dp(2, vector<i64>(2));
  dp[0] = {0, (i64)1e18};
  i64 N = S.size();
  for (i64 i = 0; i < N; i++) {
    if (S[i] == 'a') {
      dp[1][0] = min({
          dp[0][0] + X,
          dp[0][1] + Z + X,
      });
      dp[1][1] = min({
          dp[0][1] + Y,
          dp[0][0] + Z + Y,
      });
    }
    if (S[i] == 'A') {
      dp[1][0] = min({
          dp[0][0] + Y,
          dp[0][1] + Z + Y,
      });
      dp[1][1] = min({
          dp[0][1] + X,
          dp[0][0] + Z + X,
      });
    }
    dp[0] = dp[1];
  }
  cout << min(dp[0][0], dp[0][1]) << endl;
}
