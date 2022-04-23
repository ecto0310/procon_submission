// Date: Sat, 23 Apr 2022 13:26:16 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl '\n'

int main()
{
    i64 N, K;
    cin >> N >> K;
    vector<i64> t(N), y(N);
    for (i64 i = 0; i < N; i++)
    {
        cin >> t[i] >> y[i];
    }
    i64 sum = 0;
    i64 ig = 0;
    i64 ans = -1e18;
    priority_queue<i64> que;
    for (i64 i = N - 1; 0 <= i && ig <= K; i--)
    {
        if (t[i] == 2)
        {
            if (0 <= y[i])
            {
                sum += y[i];
            }
            else
            {
                que.push(y[i]);
            }
        }
        else
        {
            while (0 < que.size() && K < ig + que.size())
            {
                sum += que.top();
                que.pop();
            }
            if (ig + que.size() <= K)
            {
                ans = max(ans, sum + y[i]);
            }
            ig++;
        }
    }
    while (0 < que.size() && K < ig + que.size())
    {
        sum += que.top();
        que.pop();
    }
    if (ig + que.size() <= K)
    {
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}
