// Date: Sun, 22 Mar 2020 12:54:07 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 H, W, K;
  cin >> H >> W >> K;
  vector<string> S(H);
  for (i64 i = 0; i < H; i++)
    cin >> S[i];
  i64 ans = (H - 1) * (W - 1);
  bool cc = false;
  for (i64 i = 0; i < (1 << (H - 1)); i++)
  {
    i64 t = 0;
    for (i64 j = 0; j < (H - 1); j++)
      if (i & (1 << j))
        t++;
    i64 tmp = t;
    vector<i64> cnt(t + 1);
    for (i64 j = 0; j < W; j++)
    {
    con:;
      i64 tt = 0;
      for (i64 k = 0; k < H; k++)
      {
        if (S[k][j] == '1')
          cnt[tt]++;
        if (i & (1 << k))
          tt++;
      }
      for (i64 k : cnt)
        if (K < k)
        {
          tmp++;
          cnt = vector<i64>(t + 1);
          if (cc)
            goto en;
          cc = true;
          goto con;
        }
      cc = false;
    }
    ans = min(ans, tmp);
  en:;
  }
  cout << ans << endl;
  return 0;
}
