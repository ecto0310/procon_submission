// Date: Tue, 21 Jun 2022 05:21:50 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl '\n'

int main()
{
    i64 N, Q;
    cin >> N >> Q;
    vector<i64> A(N);
    for (auto &i : A)
    {
        cin >> i;
    }
    sort(A.begin(), A.end());
    vector<i64> sum(N + 1, 0);
    for (int i = 0; i < N; i++)
    {
        sum[i + 1] = sum[i] + A[i];
    }
    while (Q--)
    {
        i64 X;
        cin >> X;
        i64 left = -1, right = N;
        while (1 < right - left)
        {
            i64 mid = (right - left) / 2 + left;
            if (X < A[mid])
            {
                right = mid;
            }
            else
            {
                left = mid;
            }
        }
        cout << right * X - sum[right] - X * (N - right) + (sum[N] - sum[right]) << endl;
    }
    return 0;
}
