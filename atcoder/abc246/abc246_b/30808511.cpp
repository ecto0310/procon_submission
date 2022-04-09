// Date: Sat, 09 Apr 2022 12:07:46 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl '\n'

int main()
{
    i64 A, B;
    cin >> A >> B;
    double d = sqrt(A * A + B * B);
    cout << fixed << setprecision(7) << (double)A / d << " " << (double)B / d << endl;
    return 0;
}
