// Date: Tue, 10 Aug 2021 07:39:31 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int M, S, T, L;
vector<vector<int>> t;
vector<int> x, n;

struct Answer
{
    vector<int> ans;
    int score = 0;
};

Answer bestAns;

void solve()
{
    return;
}

void init()
{
    int ma = *max_element(n.begin(), n.end());
    for (int i = 1; i <= ma; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (i <= n[j])
            {
                bestAns.ans.push_back(j);
            }
        }
    }
}

void input()
{
    cin >> M >> S >> T >> L;
    t.resize(M, vector<int>(S));
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < S; j++)
        {
            cin >> t[i][j];
        }
    }
    x.resize(S);
    for (int i = 0; i < S; i++)
    {
        cin >> x[i];
    }
    n.resize(M);
    for (int i = 0; i < M; i++)
    {
        cin >> n[i];
    }
    return;
}

void output()
{
    cout << bestAns.ans.size() << endl;
    for (int i : bestAns.ans)
    {
        cout << i + 1 << " ";
    }
    cout << endl;
    return;
}

int main()
{
    input();
    init();
    solve();
    output();
    return 0;
}
