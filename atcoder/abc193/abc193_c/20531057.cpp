// Date: Sat, 27 Feb 2021 12:15:37 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main() {
    i64 N;
    cin >> N;
    set<i64> s;
    for (i64 i = 2; i <= sqrt(N); i++)
        for (i64 j = i * i; j <= N; j *= i)
            s.insert(j);
    cout << N - s.size() << endl;
    return 0;
}
