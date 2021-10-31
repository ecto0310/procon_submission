// Date: Sun, 31 Oct 2021 07:05:33 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
    vector<i64> A(3);
    cin >> A[0] >> A[1] >> A[2];
    sort(A.begin(), A.end());
    do
    {
        if (A[2] - A[1] == A[1] - A[0])
        {
            cout << "Yes" << endl;
            return 0;
        }
    } while (next_permutation(A.begin(), A.end()));
    cout << "No" << endl;
    return 0;
}
