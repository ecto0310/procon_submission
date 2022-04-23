// Date: Sat, 23 Apr 2022 12:14:09 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl '\n'

int main()
{
    i64 N, K;
    cin >> N >> K;
    vector<string> S(N);
    for (i64 i = 0; i < N; i++)
    {
        cin >> S[i];
    }
    i64 ans = 0;
    for (i64 i = 0; i < (1 << N); i++)
    {
        vector<i64> count(26);
        for (i64 j = 0; j < N; j++)
        {
            if ((i >> j) & 1)
            {
                for (char k : S[j])
                {
                    count[k - 'a']++;
                }
            }
        }
        i64 c = 0;
        for (i64 j = 0; j < 26; j++)
        {
            if (count[j] == K)
            {
                c++;
            }
        }
        ans = max(ans, c);
    }
    cout << ans << endl;
    return 0;
}
