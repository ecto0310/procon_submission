// Date: Mon, 11 Oct 2021 14:44:53 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
    i64 N;
    cin >> N;
    vector<pair<i64, i64>> edge[N];
    for (i64 i = 0; i < N - 1; i++)
    {
        i64 A, B, C;
        cin >> A >> B >> C;
        A--;
        B--;
        edge[A].push_back({B, C});
        edge[B].push_back({A, C});
    }
    vector<i64> D(N);
    for (i64 i = 0; i < N; i++)
    {
        cin >> D[i];
    }
    i64 u[2] = {};
    for (i64 i = 0; i < 2; i++)
    {
        u[0] = u[1];
        vector<i64> far(N, 1e18);
        priority_queue<pair<i64, i64>, vector<pair<i64, i64>>, greater<pair<i64, i64>>> que;
        far[u[0]] = 0;
        que.push({0, u[0]});
        while (que.size())
        {
            pair<i64, i64> p = que.top();
            que.pop();
            if (far[p.second] < p.first)
            {
                continue;
            }
            for (pair<i64, i64> j : edge[p.second])
            {
                if (far[p.second] + j.second < far[j.first])
                {
                    far[j.first] = far[p.second] + j.second;
                    que.push({far[j.first], j.first});
                }
            }
        }
        for (i64 j = 0; j < N; j++)
        {
            if (j != u[0])
            {
                far[j] += D[j];
            }
        }
        u[1] = max_element(far.begin(), far.end()) - far.begin();
    }
    vector<vector<i64>> far(2, vector<i64>(N, 1e18));
    for (i64 i = 0; i < 2; i++)
    {
        priority_queue<pair<i64, i64>, vector<pair<i64, i64>>, greater<pair<i64, i64>>> que;
        far[i][u[i]] = 0;
        que.push({0, u[i]});
        while (que.size())
        {
            pair<i64, i64> p = que.top();
            que.pop();
            if (far[i][p.second] < p.first)
            {
                continue;
            }
            for (pair<i64, i64> j : edge[p.second])
            {
                if (far[i][p.second] + j.second < far[i][j.first])
                {
                    far[i][j.first] = far[i][p.second] + j.second;
                    que.push({far[i][j.first], j.first});
                }
            }
        }
    }
    for (i64 i = 0; i < N; i++)
    {
        i64 ans = 0;
        for (i64 j = 0; j < 2; j++)
        {
            if (i != u[j])
            {
                ans = max(ans, far[j][i] + D[u[j]]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
