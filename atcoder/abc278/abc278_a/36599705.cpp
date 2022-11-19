// Date: Sat, 19 Nov 2022 12:02:15 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl '\n'

int main()
{
    i64 N, K;
    cin >> N >> K;
    vector<i64> A(N);
    for (i64 i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    for (i64 i = 0; i < K; i++)
    {
        A.erase(A.begin());
        A.push_back(0);
    }
    for (i64 i : A)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
