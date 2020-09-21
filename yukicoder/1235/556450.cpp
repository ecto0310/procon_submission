// Date: Mon, 21 Sep 2020 15:36:40 +0000
// Language: C++17
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
    i64 N;
    cin >> N;
    cout << fixed << setprecision(10) << riemann_zeta(N) << endl;
    return 0;
}
