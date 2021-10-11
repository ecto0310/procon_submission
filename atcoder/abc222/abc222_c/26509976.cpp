// Date: Mon, 11 Oct 2021 13:30:08 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

i64 win(char i, char j)
{
    if (i == j)
    {
        return 0;
    }
    if (i == 'G')
    {
        return (j == 'C' ? 1 : -1);
    }
    if (i == 'C')
    {
        return (j == 'P' ? 1 : -1);
    }
    if (i == 'P')
    {
        return (j == 'G' ? 1 : -1);
    }
    return 0;
}

int main()
{
    i64 N, M;
    cin >> N >> M;
    vector<string> A(2 * N);
    for (i64 i = 0; i < 2 * N; i++)
    {
        cin >> A[i];
    }
    map<i64, i64> w;
    for (i64 i = 0; i < 2 * N; i++)
    {
        w[i] = 0;
    }
    for (i64 i = 0; i < M; i++)
    {
        vector<pair<i64, i64>> t;
        for (pair<i64, i64> j : w)
        {
            t.push_back({j.second, j.first});
        }
        sort(t.begin(), t.end(), [](const pair<i64, i64> l, const pair<i64, i64> r)
             {
                 if (l.first == r.first)
                 {
                     return l.second < r.second;
                 }
                 return l.first > r.first;
             });
        for (i64 j = 0; j < 2 * N; j += 2)
        {
            i64 tmp = win(A[t[j].second][i], A[t[j + 1].second][i]);
            if (tmp == 1)
            {
                w[t[j].second]++;
            }
            else if (tmp == -1)
            {
                w[t[j + 1].second]++;
            }
        }
    }
    vector<pair<i64, i64>> t;
    for (pair<i64, i64> j : w)
    {
        t.push_back({j.second, j.first});
    }
    sort(t.begin(), t.end(), [](const pair<i64, i64> l, const pair<i64, i64> r)
         {
             if (l.first == r.first)
             {
                 return l.second < r.second;
             }
             return l.first > r.first;
         });
    for (i64 i = 0; i < 2 * N; i++)
    {
        cout << t[i].second + 1 << endl;
    }
    return 0;
}
