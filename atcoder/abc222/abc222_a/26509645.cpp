// Date: Mon, 11 Oct 2021 13:15:34 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
    string N;
    cin >> N;
    cout << string(4 - N.size(), '0') << N << endl;
    return 0;
}
