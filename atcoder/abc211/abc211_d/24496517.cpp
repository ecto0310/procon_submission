// Date: Sat, 24 Jul 2021 12:17:03 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

const i64 MOD = 1e9 + 7;

int main()
{
    i64 N, M;
    cin >> N >> M;
    vector<i64> edge[N];
    for (i64 i = 0; i < M; i++)
    {
        i64 A, B;
        cin >> A >> B;
        A--;
        B--;
        edge[A].push_back(B);
        edge[B].push_back(A);
    }
    vector<i64> cost(N, 1e9), cnt(N);
    vector<bool> visit(N, false);
    cost[0] = 0;
    cnt[0] = 1;
    queue<i64> que;
    que.push(0);
    while (que.size())
    {
        i64 p = que.front();
        que.pop();
        if (visit[p])
        {
            continue;
        }
        visit[p] = true;
        for (i64 i : edge[p])
        {
            if (cost[p] + 1 < cost[i])
            {
                cost[i] = cost[p] + 1;
                (cnt[i] = cnt[p]) %= MOD;
                que.push(i);
            }
            else if (cost[p] + 1 == cost[i])
            {
                (cnt[i] += cnt[p]) %= MOD;
            }
        }
    }
    cout << cnt[N - 1] << endl;
    return 0;
}
