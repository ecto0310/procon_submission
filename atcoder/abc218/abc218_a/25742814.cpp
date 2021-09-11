// Date: Sat, 11 Sep 2021 12:01:01 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
    i64 N;
    string S;
    cin >> N >> S;
    if (S[N - 1] == 'o')
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}
