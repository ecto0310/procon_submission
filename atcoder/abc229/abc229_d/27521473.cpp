// Date: Sat, 27 Nov 2021 12:11:00 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
    string S;
    i64 K;
    cin >> S >> K;
    i64 N = S.size();
    i64 r = 0, cnt = 0, ans = 0;
    for (i64 l = 0; l < N; l++)
    {
        while (r < N && cnt + (S[r] == '.' ? 1 : 0) <= K)
        {
            cnt += (S[r] == '.' ? 1 : 0);
            r++;
        }
        ans = max(ans, r - l);
        if (l == r)
        {
            r++;
        }
        else
        {
            cnt -= (S[l] == '.' ? 1 : 0);
        }
    }
    cout << ans << endl;
    return 0;
}
