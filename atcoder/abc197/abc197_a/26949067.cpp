// Date: Sun, 31 Oct 2021 07:02:50 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
    string S;
    cin >> S;
    cout << S.substr(1, S.size() - 1) << S[0] << endl;
    return 0;
}
