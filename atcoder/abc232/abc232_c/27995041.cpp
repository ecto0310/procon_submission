// Date: Sun, 19 Dec 2021 12:15:33 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
    i64 N, M;
    cin >> N >> M;
    set<i64> edgeAB[N], edgeCD[N];
    for (i64 i = 0; i < M; i++)
    {
        i64 A, B;
        cin >> A >> B;
        A--;
        B--;
        edgeAB[A].insert(B);
        edgeAB[B].insert(A);
    }
    for (i64 i = 0; i < M; i++)
    {
        i64 C, D;
        cin >> C >> D;
        C--;
        D--;
        edgeCD[C].insert(D);
        edgeCD[D].insert(C);
    }
    vector<i64> n(N);
    for (i64 i = 0; i < N; i++)
    {
        n[i] = i;
    }
    do
    {
        bool ok = true;
        for (i64 i = 0; i < N; i++)
        {
            if (edgeAB[i].size() != edgeCD[n[i]].size())
            {
                ok = false;
                continue;
            }
            i64 size = edgeAB[i].size();
            for (i64 j : edgeAB[i])
            {
                if (edgeCD[n[i]].count(n[j]) == 0)
                {
                    ok = false;
                }
            }
        }
        if (ok)
        {
            cout << "Yes" << endl;
            return 0;
        }
    } while (next_permutation(n.begin(), n.end()));
    cout << "No" << endl;
    return 0;
}
