// Date: Sat, 27 Nov 2021 12:01:52 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
    string S1, S2;
    cin >> S1 >> S2;
    if ((S1 == "#." && S2 == ".#") || (S1 == ".#" && S2 == "#."))
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }
    return 0;
}
