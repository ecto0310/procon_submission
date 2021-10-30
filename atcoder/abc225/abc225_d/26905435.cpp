// Date: Sat, 30 Oct 2021 12:23:50 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
    i64 N, Q;
    cin >> N >> Q;
    vector<i64> t(N + 1, -1), b(N + 1, -1);
    for (i64 _ = 0; _ < Q; _++)
    {
        i64 q;
        cin >> q;
        if (q == 1)
        {
            i64 x, y;
            cin >> x >> y;
            b[x] = y;
            t[y] = x;
        }
        else if (q == 2)
        {
            i64 x, y;
            cin >> x >> y;
            b[x] = -1;
            t[y] = -1;
        }
        else
        {
            i64 x;
            cin >> x;
            while (t[x] != -1)
            {
                x = t[x];
            }
            vector<i64> train;
            train.push_back(x);
            while (b[x] != -1)
            {
                train.push_back(b[x]);
                x = b[x];
            }
            cout << train.size() << " ";
            for (i64 i : train)
            {
                cout << i << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
