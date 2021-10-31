// Date: Sun, 31 Oct 2021 06:57:45 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
    i64 N;
    cin >> N;
    if ((i64)(N * 1.08) < 206)
    {
        cout << "Yay!" << endl;
    }
    else if ((i64)(N * 1.08) == 206)
    {
        cout << "so-so" << endl;
    }
    else
    {
        cout << ":(" << endl;
    }
    return 0;
}
