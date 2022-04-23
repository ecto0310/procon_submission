// Date: Sat, 23 Apr 2022 12:08:56 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl '\n'

int main()
{
    string S;
    cin >> S;
    bool l = false;
    bool s = false;
    set<char> cl;
    for (char i : S)
    {
        if ('a' <= i && i <= 'z')
        {
            s = true;
        }
        else
        {
            l = true;
        }
        if (cl.count(i) != 0)
        {
            cout << "No" << endl;
            return 0;
        }
        cl.insert(i);
    }
    if (s && l)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}
