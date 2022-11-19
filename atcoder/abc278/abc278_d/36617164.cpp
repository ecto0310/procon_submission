// Date: Sat, 19 Nov 2022 12:27:26 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl '\n'

int main()
{
    i64 N;
    cin >> N;
    vector<pair<i64, i64>> A(N);
    for (i64 i = 0; i < N; i++)
    {
        cin >> A[i].first;
        A[i].second = -1;
    }
    i64 Q;
    cin >> Q;
    i64 last = -1, value = -1;
    for (i64 i = 0; i < Q; i++)
    {
        i64 t;
        cin >> t;
        if (t == 1)
        {
            i64 xq;
            cin >> xq;
            last = i;
            value = xq;
        }
        else if (t == 2)
        {
            i64 iq, xq;
            cin >> iq >> xq;
            iq--;
            if (A[iq].second < last)
            {
                A[iq] = {value + xq, i};
            }
            else
            {
                A[iq] = {A[iq].first + xq, i};
            }
        }
        else
        {
            i64 iq;
            cin >> iq;
            iq--;
            if (A[iq].second < last)
            {
                A[iq] = {value, i};
            }
            cout << A[iq].first << endl;
        }
    }
    return 0;
}
